// 1_전처리기12.c

#include <stdio.h>

/* 잘못된 코드 */
// #define cstring char *
// 매크로 정의는 타입에 대한 범위 규칙이 제대로 적용되지 않습니다.
//  => 타입을 재정의할 때는 typedef를 이용해야 합니다.

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