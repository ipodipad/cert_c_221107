// stack.c
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack
{
  void **arr;
  int top;
  int size;
};

void print_stack(const STACK *s)
{
  printf("top=%d, size=%d\n", s->top, s->size);
}

STACK *create_stack(int size)
{
  printf("create_stack: %d\n", size);
  STACK *stack = calloc(1, sizeof(STACK));
  if (stack == NULL)
  {
    return NULL;
  }

  stack->arr = calloc(size, sizeof(void *));
  if (stack->arr == NULL)
  {
    free(stack);
    return NULL;
  }

  stack->size = size;
  return stack;
}