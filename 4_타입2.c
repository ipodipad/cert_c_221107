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

#if 0
int main(void)
{
  u_int16_t x = 45000;
  u_int16_t y = 50000;
  // 2,250,000,000

  int64_t z = x * y; /* 연산의 결과가 오버플로우 - 미정의 동작 */
  printf("%lld\n", z);

  /* 해결 방법 */
  z = (int64_t)x * y;
  printf("%lld\n", z);

  return 0;
}
#endif

// 5. 정수 변환 규칙
//   1) 정수 순위(Rank)
//     - long long > long > int > short > signed char
//     - unsigned long long > unsigned long > unsigned int > unsigned short > unsigned char

//   2) 산술 변환 규칙
//    => 연산을 수행하기 전에 피연산자의 타입을 변환하고, 연산을 수행합니다.
//    "이항 연산의 경우 두개의 피연산자가 같은 타입으로 변환됩니다."
//    1. 두 개의 피연산자가 같은 타입이면 변환하지 않습니다.
//    2. 두 개의 피연산자가 같은 정수 타입이면, 범위가 큰 타입으로 변환됩니다.
//    3. 부호 없는 정수 타입의 피연산자가 다른 피연산자의 순위보다 크거나 같은 경우
//       부호 있는 정수 타입의 피연산자는 부호 없는 정수 타입으로 변환됩니다.
//    4. 부호 있는 정수 타입의 피연산자가 부호 없는 타입의 모든 값을 표현할 수 있는
//       경우 부호 없는 정수 타입의 피연산자는 부호 있는 정수 타입으로 변환됩니다.
//    5. 부호 있는 정수 타입의 피연산자가 부호 없는 타입의 모든 값을 표현할 수 없는
//       경우, 부호 있는 정수 타입의 피연산자는 동일 타입의 부호 없는 타입으로
//       두 피연산자 모두 변환됩니다.

int main(void)
{
  int a = 100;
  int b = INT_MAX;

  long c = 100;
  long d = LONG_MAX;
  // a + b -> int
  // => 같은 타입이면 변환되지 않습니다.

  int a2 = INT_MAX;
  long long b2 = INT_MAX;
  // a2 + b2 -> long long

  // 부호 없는 피연산자의 순위가 크거나 같은 경우, 부호 없는 정수로 변환됩니다.
  int a3 = INT_MAX;
  unsigned int b3 = 10;
  // a3 + b3 -> unsigned int

  int a4 = INT_MAX;
  unsigned short b4 = 10;
  // a4 + b4 -> int

  long long a5 = 10;
  unsigned int b5 = INT_MAX;
  // a5 + b5 -> long long

  // long, long long => 8바이트
  long long a6 = 20;
  unsigned long b6 = LONG_MAX;
  // 부호 있는 정수 타입의 피 연산자가 부호 없는 타입의 모든 값을 표현할 수 없는 경우
  // 부호 있는 정수 타입의 피연산자의 동일 타입의 부호 없는 타입으로 두 피연산자
  // 모두 변경됩니다.

  return 0;
}
