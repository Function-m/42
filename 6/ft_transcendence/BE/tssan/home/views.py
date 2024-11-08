from django.shortcuts import render, redirect
from django.http import HttpResponse,HttpResponseBadRequest,JsonResponse, HttpResponseRedirect
from dicebe.models import Stat
from .models import User
from dicebe.views import validTokenCheck

def wrongUrl():
	res = HttpResponseRedirect('https://localhost/404/')
	return res

def profilebe(request) :
	if request.method != 'GET' :
		return HttpResponseRedirect('https://localhost/404/')
	nick = validTokenCheck(request)
	if nick is None:
		return HttpResponseRedirect('https://localhost/404/')
	if User.objects.filter(nick=nick).exists() is False :
		return HttpResponseBadRequest('400 user not found')
	user = User.objects.filter(nick=nick).values('nick', 'name', 'email')
	record = user[0]
	data = {
		'nick' : record['nick'],
		'name': record['name'],
		'email': record['email']
	}
	return JsonResponse(data)

def anonybe(request) :
	if request.method != 'GET':
		return HttpResponseRedirect('https://localhost/404/')
	nick = validTokenCheck(request)
	if nick is None:
		return HttpResponseRedirect('https://localhost/404/')
	if User.objects.filter(nick=nick).exists() is False :
		return HttpResponseBadRequest('400 user not found')
	user = User.objects.get(nick=nick)
	username = user.name
	lastname = username.split(' ')
	user.name = lastname[0]
	user.save()
	return HttpResponse(status=200)
	
def delUserbe(request) :
	if request.method != 'DELETE':
		return HttpResponseRedirect('https://localhost/404/')
	nick = validTokenCheck(request)
	if nick is None:
		return HttpResponseRedirect('https://localhost/404/')
	if User.objects.filter(nick=nick).exists() is False :
			return HttpResponseBadRequest('400 user not found')
	try:
		deluser = User.objects.get(nick=nick)
		if Stat.objects.filter(nick=nick).exists():
			delstat = Stat.objects.get(nick=nick)
			delstat.delete()
		deluser.delete()
		return HttpResponse(f'{nick}was deleted.', status=200)
	except User.DoesNotExist:
		return HttpResponseBadRequest('not found')