from django.urls import path
from . import views

urlpatterns = [
    path('anonybe/', views.anonybe, name='home_anony'),
    path('profilebe/', views.profilebe, name='home_profile'),
    path('deluserbe/', views.delUserbe, name='home_deluser')
]