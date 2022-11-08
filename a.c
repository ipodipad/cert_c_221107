// a.c

#include <stdio.h>

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