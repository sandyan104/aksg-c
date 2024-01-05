#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"

struct UserData users[2] = {{"w", "2"}, {"q", "1"}};

int login(char *username, char *password)
{
  int isUser = 0, i, length;

  length = sizeof(users) / sizeof(users[0]);

  for (i = 0; i < length; i++)
  {
    if ((strcmp(users[i].username, username) == 0) && (strcmp(users[i].password, password) == 0))
    {
      isUser = 1;
    }
  }

  return isUser;
}