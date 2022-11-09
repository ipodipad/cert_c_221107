// user.c
#include "user.h"

#include <stdio.h>

struct user
{
  char name[32];
  char password[32];
};

USER current = {"admin",
                "admin_password"};

void debug_print(USER *user)
{
  printf("User: %s / %s\n", user->name, user->password);
}

USER *get_current_user(void)
{
  return &current;
}

void print_user(USER *user)
{
  printf("User: %s\n", user->name);
}