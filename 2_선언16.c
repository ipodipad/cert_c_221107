// 2_선언16.c
#include <stdio.h>

#include "user.h"

int main(void)
{
  USER *current = get_current_user();

  print_user(current);

  // printf("%s\n", current->password); /* Compile Error */

  return 0;
}