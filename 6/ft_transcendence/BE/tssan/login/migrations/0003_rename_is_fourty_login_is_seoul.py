# Generated by Django 5.0.6 on 2024-07-03 09:54

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('login', '0002_login_email_code'),
    ]

    operations = [
        migrations.RenameField(
            model_name='login',
            old_name='is_fourty',
            new_name='is_seoul',
        ),
    ]