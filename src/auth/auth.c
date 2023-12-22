#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"

struct UserData users = {"edisupono", "admintunggal"};

int login(char *username, char *password)
{
  int isUser = 0;

  if ((strcmp(users.username, username) == 0) && (strcmp(users.password, password) == 0))
  {
    isUser = 1;
  }
    return isUser;
}