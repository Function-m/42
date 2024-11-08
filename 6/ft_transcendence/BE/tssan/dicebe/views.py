from django.shortcuts import render
from django.http import HttpResponse,HttpResponseBadRequest,HttpResponseRedirect, JsonResponse

from .models import Stat
from login.models import Login
import jwt, requests, json, os
from login.views import isValidToken

def validTokenCheck(request) :
	cookie_jwt = request.headers.get('Authorization')
	if not cookie_jwt:
		return None

	result = isValidToken(cookie_jwt)
	if not result:
		return None
	return result

def stat(request) :
	if request.method != 'GET':
		return HttpResponseRedirect('https://localhost/404/')
	nick = validTokenCheck(request)
	if nick is None:
		return HttpResponseRedirect('https://localhost/404/')
	if Stat.objects.filter(nick=nick).exists() is False :
		Stat.objects.create(nick=nick, odd_win=0, odd_lose=0, even_win=0, even_lose=0)
	stat= Stat.objects.filter(nick=nick).values('odd_win','odd_lose', 'even_win', 'even_lose')
	record = stat[0]
	odd = {
		'odd_win': record['odd_win'],
		'odd_lose': record['odd_lose']
	}
	even = {
		'even_win': record['even_win'],
		'even_lose': record['even_lose']
	}
	data = {
		'nick' : nick,
		'odd': odd,
		'even': even
	}
	return JsonResponse(data)

def result(request) :
	if request.method != 'POST':
		return HttpResponseRedirect('https://localhost/404/')
	nick = validTokenCheck(request)
	if nick is None:
		return HttpResponseBadRequest('token 만료 재로그인')
	data = json.loads(request.body.decode())
	try :
		result = data['data']['type']
	except Exception:
		return HttpResponseBadRequest('400 wrong data')
	if Stat.objects.filter(nick=nick).exists() is False :
		Stat.objects.create(nick=nick, odd_win=0, odd_lose=0, even_win=0, even_lose=0)
	stat = Stat.objects.get(nick=nick)
	if result == 0 :
		stat.even_win += 1
		stat.odd_lose += 1
		stat.save()
	elif result == 1 :
		stat.odd_win += 1
		stat.even_lose += 1
		stat.save()
	return (HttpResponse(status=200))

def index(request) :
	return HttpResponseRedirect('https://localhost/404/')