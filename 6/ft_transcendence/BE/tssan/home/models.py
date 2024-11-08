from django.db import models

# Create your models here.
class User(models.Model) :
	nick = models.CharField(max_length = 30, primary_key=True)
	name = models.CharField(max_length = 30)
	email = models.EmailField(max_length = 128)