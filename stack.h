// stack.h

#ifndef STACK_H
#define STACK_H

struct stack
{
  void **arr;
  int top;
  int size;
};

typedef struct stack STACK;

extern STACK *create_stack(int size);

#endif