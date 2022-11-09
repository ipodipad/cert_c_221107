// a.c

#include <stdio.h>

extern const int c = 42;
// 핵심: 통용범위 지정자를 명시해야 합니다.
// => C하고 C++이 다르게 동작하기 때문입니다.

// extern: 선언에서만 사용합니다.
extern int x;
// 외부 전역 변수 참조를 위한 선언

// internal linkage
static void goo(void)
{
}

// external linkage
void foo(void)
{
  printf("x: %d\n", x);
}