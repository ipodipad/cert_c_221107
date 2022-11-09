// 2_선언15.c
#include <stdio.h>

// 스택을 만들어봅시다.
#include "stack.h"

int main(void)
{
  STACK *stack = create_stack(10);
  if (stack == NULL)
  {
    fprintf(stderr, "create_stack error\n");
    return 1;
  }

  // ...

  return 0;
}