// stack.h

#ifndef STACK_H
#define STACK_H

#if 0
// 외부에서 멤버를 변경할 수 있습니다.
struct stack
{
  void **arr;
  int top;
  int size;
};

typedef struct stack STACK;
extern STACK *create_stack(int size);
#endif

// 전방 선언
struct stack;

typedef struct stack STACK;
extern STACK *create_stack(int size);

#endif