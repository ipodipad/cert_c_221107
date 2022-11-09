#include <stdio.h>

#define private public
#define class struct
#include "test.h"
#undef private
#undef public

// test.cpp
int main(void)
{
  struct user user;

  printf("%d\n", user.age);

  return 0;
}