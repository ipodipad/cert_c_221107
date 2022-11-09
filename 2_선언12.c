// 2_선언12.c
#include <stdio.h>

#if 0
// Out Parameter를 통해 결과를 전달받는 함수입니다.
int divide(int devided, int divisor, int *result)
{
  // 입력된 인자가 유효한지 반드시 검증해야 합니다.
  if (divisor == 0)
  {
    return -100;
  }

  if (result == NULL)
  {
    return -200;
  }

  *result = devided / divisor;
  return 0;
}

int main(void)
{
  int data;

  // 함수가 결과를 반환하면, 반드시 반환값에 대한 체크가 필요합니다.
  divide(10, 4, &data);

  printf("%d\n", data);
}
#endif
// 문제점: 반환 타입의 정보만으로 함수가 결과를 반환하는지,
//       오류 여부를 반환하는지 구분하기 어렵습니다.
// 해결방법
//  > 에러를 반환하는 함수는 함수의 반환타입을 에러 타입으로 사용하는 것이 좋습니다.
//    에러 코드도 심볼릭 상수를 통해 제공하는 것이 좋습니다.

enum
{
  DIVISION_BY_ZERO = -100,
  INVALID_POINTER = -200
};

typedef int error_t;
error_t divide(int devided, int divisor, int *result)
{
  // 입력된 인자가 유효한지 반드시 검증해야 합니다.
  if (divisor == 0)
  {
    return DIVISION_BY_ZERO;
  }

  if (result == NULL)
  {
    return INVALID_POINTER;
  }

  *result = devided / divisor;
  return 0;
}

int main(void)
{
  int data;
  error_t error;

  // 함수가 결과를 반환하면, 반드시 반환값에 대한 체크가 필요합니다.
  error = divide(10, 4, &data);
  if (error != 0)
  {
    fprintf(stderr, "divide error: %d\n", error);
  }
  else
  {
    printf("%d\n", data);
  }
}