from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='dice_error'),
    path('stat/', views.stat, name='dice_stat'),
    path('result/', views.result, name='dice_result')
]