// 2_선언17.c
#include <stdio.h>

#include "sample.h"

// external linkage
// => 파일에 두어야 합니다.
//    헤더가 둘 경우 심볼 충돌이 발생합니다.

// internal linkage
// => 헤더: 어디에서든 사용이 가능하다.
//   예) 상수(enum, macro), 인라인 함수
// => 소스: 소스 파일 내부에서만 접근이 하도록 하겠다. : private 개념

int main(void)
{
  int result = add(10, 20);
  printf("result: %d\n", result);

  return 0;
}