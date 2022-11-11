// 4_타입10.c
#include <stdio.h>

// 1. >> 쉬프트
//   부호 있는 타입: 부호 비트로 채워집니다. => 산술 쉬프트
//   부호 없는 타입: 0으로 채워집니다.     => 논리 쉬프트

// 2. 비트 연산에서 논리 쉬프트가 필요하면, unsigned 타입을 명시적으로 사용해야 합니다.

// 3. 비트 연산(~, >>, <<, &, |, ^)
//    signed에 대한 비트 연산은 미지정 동작입니다.
//    => 컴파일러의 구현마다 다른 동작의 가능성이 존재한다.
//    => 비트 연산의 대상 타입은 unsigned를 사용해야 합니다.

// 4. 쉬프트 연산에서 음수 또는 대상체의 비트수 이상으로 쉬프트를 수행하는 것은
//    미정의 동작입니다.

#if 0
int main(void)
{
  int a = 0xABABABAB;
  printf("%X\n", a >> 24); // 0xffffffab;

  printf("%X\n", (unsigned int)a >> 24); // 0xab;
  printf("%X\n", (a >> 24) & 0xFF);      // 0xab;

  unsigned b = 0xABABABAB;
  printf("%X", b >> 24); // 0xab;

  return 0;
}
#endif

#include <limits.h>
// CHAR_BIT

#define BITS(x) (sizeof(x) * CHAR_BIT)

int main(void)
{
  unsigned int n = 0xABABABAB;

  size_t s;
  scanf("%lu", &s);

  if (s < BITS(n))
  {
    printf("%X\n", n >> s);

    // printf("%X\n", n >> -10); /* 미정의 동작 */
    // printf("%X\n", n >> 32); /* 미정의 동작 */
    // printf("%X\n", n >> 33); /* 미정의 동작 */
  }
  else
  {
    printf("Invalid\n");
  }

  return 0;
}