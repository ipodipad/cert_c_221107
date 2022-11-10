// 3_표현식12.c

#include <stdio.h>

struct X
{
  char a[8];
  int arr[10];
};

struct X foo(void)
{
  struct X result = {"Hello"};
  return result;
}

struct X goo(void)
{
  struct X result = {"World"};
  return result;
}

// 1. 함수로 반환되는 구조체의 값을 바로 접근하는 것은 미정의 동작입니다. => C90
// => gcc 3_표현식12.c -std=c90

// 2. 함수로 반한되는 구조체의 결과의 값을 바로 수정하면, 미정의 동작입니다. => C99
#if 0
int main(void)
{
  foo().arr[5] = 42; /* 미정의 동작 - C99 */

  printf("%s %s\n", foo().a, goo().a); /* 미정의 동작 - C90 */

  return 0;
}
#endif

#if 1
// 해결 방법
// > 반환되는 값을 변수에 저장(복사)하고 사용해야 합니다.
int main(void)
{
  struct X rf = foo();
  struct X rg = goo();

  rf.arr[5] = 100; /* OK */

  printf("%s %s\n", rf.a, rg.a); /* OK */
  return 0;
}
#endif