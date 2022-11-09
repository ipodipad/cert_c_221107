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

// 스택의 설계자가 제공하는 기능을 통해서만,
// 멤버 데이터에 접근이 가능합니다.
extern void print_stack(const STACK *s);

#endif