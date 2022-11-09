// 2_선언6.c
#include <stdio.h>
#include <string.h>

// 1. 프로그램에서 상수 리터럴을 직접 사용할 경우,
//    소스 코드의 가독성이 떨어집니다.
//    : 정수 상수의 경우 목적을 파악하기 어려울 수 있기 때문에, 매직 넘버라고 합니다.
//  => 프로그램 코드에서 상수 리터럴을 직접 사용하는 대신, 적절하게 이름있는 심볼릭 상수를
//     사용해야 합니다.
//     "코드의 의도를 명확하게 표현할 수 있습니다."
#if 0
int main(void)
{
  int n;

  int arr1[10] = {10, 20, 30};
  int arr2[20] = {100, 200, 300};

  memcpy(arr2, arr1, 10);

  for (int i = 0; i < 10; ++i)
  {
    printf("%d\n", arr2[i]);
  }

  return 0;
}
#endif

#if 1
// 2. C에서 심볼릭 상수를 만드는 방법 3가지
//  1) const로 지정된 상수
//      : C 표준과 C++ 표준에서 다르게 동작합니다.
const int SRC_SIZE = 10;
const int DEST_SIZE = 20;

//  평가 시점: 실행 시간, 런타임 상수
// 메모리 소모: 있음
//  타입 체크: 있음
// => C의 const 변수는 상수 표현식이 아니기 때문에,
//    배열의 크기 / 열거 상수의 값 / case 상수의 값으로 사용될 수 없습니다.

//  2) 열거형 상수
// enum
// {
//   SRC_SIZE = 10,
//   DEST_SIZE = 20
// };
//  평가 시점: 컴파일 타임
// 메모리 소모: 없음
//  타입 체크: 있음
// > 열거형 상수는 정수로 나타낼 수 있는 값을 갖는 정수 상수 식에 대해서
//   사용할 수 있습니다.

//  3) 매크로 상수
// #define SRC_SIZE (10)
// #define DEST_SIZE (20)

//  평가 시점: 전처리
// 메모리 소모: 없음
//  타입 체크: 없음
enum AAA
{
  HELLO = SRC_SIZE /* ERROR */
};

int main(void)
{
  int n;
  switch (n)
  {
  case SRC_SIZE: /* ERROR */
    printf("...\n");
    break;
  }

  int arr1[SRC_SIZE] = {10, 20, 30};
  int arr2[DEST_SIZE] = {100, 200, 300};

  memcpy(arr2, arr1, SRC_SIZE);

  for (int i = 0; i < DEST_SIZE; ++i)
  {
    printf("%d\n", arr2[i]);
  }

  return 0;
}
#endif