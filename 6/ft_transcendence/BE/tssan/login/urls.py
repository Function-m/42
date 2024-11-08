from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='login_index'),
    path('twofactor/', views.twofactor, name='login_twofactor'),
    path('twofactor/emailAuth/', views.emailAuth, name='login_emailAuth'),
    path('check/', views.check, name='login_check')
]