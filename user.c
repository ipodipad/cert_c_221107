// user.c
#include "user.h"

#include <stdio.h>

struct user
{
  char name[32];
  char password[32];
};

// 외부에서 접근하면 안되는 전역 변수와 전역 함수에 대해서는
// 반드시 static으로 만들어야 합니다.
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