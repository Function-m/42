from django.db import models
from home.models import User

class Login(models.Model):
	nick = models.OneToOneField(User, on_delete=models.CASCADE,primary_key=True)
	is_seoul = models.BooleanField(default=False)
	email_code = models.CharField(max_length=6, default='')
