// 4_타입.c
#include <stdio.h>

// 1. 사용하는 아키텍처의 데이터 모델에 대해서 제대로 이해해야 합니다.
//    데이터 모델은 표준 데이터 타입에 할당되는 크기를 정의합니다.

// 2. 아키텍처 또는 컴파일러의 종류에 따라서, 기본 타입의 크기가 다릅니다.
//    C 표준은 char 타입에 대해서만 1바이트로 규정하고 있습니다.

// 3. 표준 타입을 사용할 때, stdint.h 있는 타입 정의를 사용한다면
//    특정 데이터 모델에 종속적이지 않은 제한된 타입을 사용할 수 있습니다.

// 4. limits.h 를 이용해서, 주어진 타입에 대한 범위를 파악할 수 있습니다.
#include <limits.h>
#include <stdint.h> // C99

int main(void)
{
  printf("%d\n", INT_MAX);   // limits.h
  printf("%d\n", INT32_MAX); // stdint.h

  int8_t a;  // 부호 있는 1바이트 정수
  int64_t b; // 부호 있는 8바이트 정수

  uint16_t c;

  int_least32_t d;
  // 플랫폼에서 지원하는 최소 32비트의 부호 있는 정수

  uint_fast32_t f;
  // 플랫폼에서 지원하는 가장 빠른 타입 중 32비트 부호 없는 정수

  return 0;
}