// 2_선언15.c
#include <stdio.h>

// 스택을 만들어봅시다.
#include "stack.h"

// 구조체를 불투명한 타입을 통해 제공한다면,
// 외부에서 값을 함부로 변경하는 것을 방지할 수 있습니다.
// => 정보 은닉(Information Hiding)

int main(void)
{
  STACK *stack = create_stack(10);
  if (stack == NULL)
  {
    fprintf(stderr, "create_stack error\n");
    return 1;
  }

// 구조체의 멤버의 데이터를 외부에서 함부로 변경이 가능합니다.
#if 0
  printf("%d %d\n", stack->top, stack->size);
  stack->top = 10;
  stack->size = 100;

  printf("%d %d\n", stack->top, stack->size);
#endif

  return 0;
}