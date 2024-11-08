from django.db import models

class Stat(models.Model) :
	nick = models.CharField(max_length = 30, primary_key=True, default="nick")
	odd_win = models.IntegerField(default=0)
	odd_lose = models.IntegerField(default=0)
	even_win = models.IntegerField(default=0)
	even_lose = models.IntegerField(default=0)
	