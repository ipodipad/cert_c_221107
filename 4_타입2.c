// 4_타입2.c
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

// 1. 정수 변환 규칙에 대해서 이해하는 것이 중요합니다.
//  "변환(캐스팅)"
//  - 명시적인(explicit) 캐스팅: 개발자가 캐스팅 연산자를 통해 타입을 변환
//  - 암묵적인(implicit) 캐스팅: 다른 타입임에도 캐스팅 연산자를 사용하지 않고도
//                           변환이 수행됩니다.

// 2. 잘못된 캐스팅이 수행될 경우, 데이터가 손실되거나 잘못 해석될 수 있습니다.

// 3. 오버플로우
//  => 부호 있는 정수가 자신이 표현할 수 있는
//     범위를 벗어나는 연산을 수행하였을 때
//  => 미정의 동작

// 4. 정수 프로모션(Promotion, 상승 변환)
// > int 보다 작은 정수 타입은 연산이 수행될 때, int 또는 unsigned int로 변환됩니다.
#if 0
int main(void)
{
  signed char c1 = 100;
  signed char c2 = 100;
  printf("%d\n", SCHAR_MAX);

  int n = c1 + c2;
  printf("%d\n", n);

  short s1 = SHRT_MAX;
  short s2 = 1;
  printf("%d\n", SHRT_MAX);

  n = s1 + s2;
  printf("%d\n", n);
  unsigned short s3 = SHRT_MAX;
  unsigned short s4 = SHRT_MAX;

  signed char c3 = 100;
  signed char c4 = 100;
  signed char c5 = 4;

  return 0;
}
#endif

// 오른쪽 쉬프트
//  부호 있는 정수: 부호비트(MSB)   - Arithmetic Shift
//  부호 없는 정수: 0으로 채워집니다. - Logical Shift
#if 0
int main(void)
{
  uint8_t port = 0x5a;
  uint8_t result = (~port) >> 4;
  printf("%x\n", result);

  //  0x5a: 0101 1010
  // ~0x5a: 1010 0101
  //   >>4: 0000 1010
  //  => 0x0a

  //      0x5a: 0101 1010
  // promotion: 0000 0000 0000 0000 0000 0000 0101 1010
  //     ~0x5a: 1111 1111 1111 1111 1111 1111 1010 0101
  //       >>4: 1111 1111 1111 1111 1111 1111 1111 1010
  //    result: 1111 0101
  //  => 0xfa

  /* 해결 방법 */
  result = (uint8_t)(~port) >> 4;
  printf("%x\n", result);

  result = (~port & 0xff) >> 4;
  printf("%x\n", result);

  return 0;
}
#endif

int main(void)
{
  u_int16_t x = 45000;
  u_int16_t y = 50000;
  // 2,250,000,000

  int64_t z = (int64_t)x * y; /* 연산의 결과가 오버플로우 - 미정의 동작 */
  printf("%lld\n", z);

  return 0;
}