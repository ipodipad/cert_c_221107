// 3_표현식5.c
#include <stdio.h>

// a         b    c
// |-|-|-|-| |-|-|-|x|

// 핵심: 구조체의 크기는 멤버 변수의 총합과 일치하지 않을 수 있습니다.

// C표준
// => 구조체에 이름없는 패딩이 들어갈 수 있으며, 앞쪽에는 위치하지 않는다.
//  - CPU가 멤버의 메모리에 빠르게 접근하기 위해서 입니다.
//  - 구조체의 패딩이 어떻게 생성될지는 컴파일러의 구현에 의존합니다.
//    => 미지정
#if 0
typedef struct data
{
  int a;   // 4byte
  short b; // 최초 4, 2byte
  char c;  // 1byte
} DATA;

int main(void)
{
  DATA data = {10, 20, 'A'};

  printf("%lu\n", sizeof(DATA));

  return 0;
}
#endif

// 구조체의 멤버 변수가 선언된 순서에 따라서 구조체의 크기가 달라질 수 있습니다.

// 컴파일러의 확장 명령을 통해서 구조체의 정렬을 조절할 수 있습니다.

// #pragma pack(1)
// => 멤버 데이터의 크기에 의해서 결정됩니다.

//   n    p      d     c
// |----|xxxx|--------|-xxxxxxx|

#pragma pack(push, 1)
struct AAA
{
  int n;
  // char padding1[4];
  double d;
  char c;
  // char padding2[7];
};
#pragma pack(pop)

//   n   c    d
// |----|-xxx|--------|
struct BBB
{
  int n;
  char c;
  // char padding[3];
  double d;
};

int main(void)
{
  printf("%lu\n", sizeof(struct AAA));
  printf("%lu\n", sizeof(struct BBB));

  return 0;
}