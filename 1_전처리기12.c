// 1_전처리기12.c

#include <stdio.h>

/* 잘못된 코드 */
// #define cstring char *
// 매크로 정의는 타입에 대한 범위 규칙이 제대로 적용되지 않습니다.
//  => 타입을 재정의할 때는 typedef를 이용해야 합니다.
#if 0
typedef char *cstring;

// char *p1, p2;
//   p1 => char*
//   p2 => char

// char *p1, *p2;
//   p1 => char*
//   p2 => char*

int main(void)
{
  /* OK */
  // cstring p1;
  // cstring p2;

  // cstring p1, p2; /* NO */

  p1 = "Tom";
  printf("%s\n", p1);

  p2 = "Seoul";
  printf("%s\n", p2);

  return 0;
}
#endif

// C/C++ 에서 타입을 구하는 방법
//  - 이름을 뺀 나머지가 타입입니다.

int main(void)
{
  int a;
  // a의 타입은 무엇입니까?
  // => int

  int x[3] = {10, 20, 30};
  // x의 정확한 타입은 무엇입니까?
  // => int[3]
  // => 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다.
  //   : Decay(부식된다)
  // => Decay 예외
  //   1) sizeof
  //   2) &

  int *p = x;
  // int *p = &x[0];
  printf("%lu\n", sizeof(x));
  printf("%lu\n", sizeof(int[3]));

  int(*p2)[3] = &x;

  return 0;
}