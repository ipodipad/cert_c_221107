// 4_타입4.c

#include <stdio.h>

// 1. 비트 필드의 멤버가 signed로 결정될지, unsigned로 결정은
//    미지정 동작입니다.
//   => 컴파일러의 구현에 의존합니다.
//   반드시 비트 필드를 사용할 때, signed와 unsigned를 명시해야 합니다.

// 2. 정수 프로모션 규칙이 적용됩니다.

// 비트 필드 구조체
struct bits
{
  // int a : 8; // 8비트 /* NO */
  // int b : 4; // 4비트 /* NO */
  signed int a : 8;
  signed int b : 8;

  unsigned int c : 8;
  unsigned int d : 8;

  // unsigned int로 처리되는 경우, int가 원래 유형의 모든 값을 포함할 수 있으므로, 필드 크기가 int보다 작은 경우 int로 승격됩니다.
  unsigned int e1 : 31;
  unsigned int f1 : 31;

  // 필드 너비가 int와 동일한 경우, unsigned int로 승격합니다.
  unsigned int e2 : 32;
  unsigned int f2 : 32;

  // signed int x : 1; /* 부호 비트 밖에 존재하지 않습니다.*/
  unsigned int x : 1; // 반드시 부호 없이 명시해야 합니다.
};

int main(void)
{
  struct bits b = {10, 20, 30, 40};
  // b.a + b.b => int
  // b.c + b.d => int

  // b.e1 + b.f1 => int
  // b.e2 + b.f2 =>

  return 0;
}