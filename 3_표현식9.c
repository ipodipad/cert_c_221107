// 3_표현식9.c

#include <stdio.h>
#include <stdlib.h>

// 핵심: 프로그램에서 타입의 크기를 가정하면 안됩니다.
// => 대부분의 타입의 크기가 컴파일러마다 다르고, 동일한 컴파일러라고 하더라도
//    컴파일러의 버전에 따라, 플랫폼에 따라 다릅니다.

// int => 16bit, 2바이트
// int => 32bit, 4바이트
//        64bit, 4바이트

// long => 16, 32bit: 4바이트
//         MSVC 64bit: 4바이트
//         GCC, Clang 64bit: 8바이트

// C 표준은 char의 크기를 1바이트로 명시적으로 정의합니다.
//  - 문자 또는 문자 배열에 기반한 모든 크기는 sizeof 연산을 사용하지 않아도
//    안전합니다.

int main(void)
{
  int n = 100;
  int *p = malloc(4); /* 잘못된 코드 */
  *p = n;

  char c = 'A';
  // int *pc = malloc(1); /* OK */
  int *pc = malloc(sizeof(char)); /* OK */
  *pc = c;

  free(p);
  free(pc);

  return 0;
}