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

#if 0
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
#endif

#include <stdio.h>
#include <string.h>

// strcpy_s, scanf_s ... _s 계열의 함수: C11 Annex K 확장 라이브러리입니다.
// => 표준에서 강제하고 있지 않습니다.
// => 일부 플랫폼에서는 해당 기능의 구현을 제공하고 있지 않습니다.

#ifndef __STDC_SECURE_LIB__
typedef int errno_t;
#endif

int main(void)
{
  errno_t error;

  char buf[10];

  // warning C4996 : 'strcpy' : This function or variable may be unsafe.Consider using strcpy_s instead.
  // To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.
  // strcpy(buf, "hello");

  // strcpy_s: 버퍼 오버플로우가 발생할 경우, abort()가 수행됩니다.
  error = strcpy_s(buf, sizeof(buf), "hello");
  printf("%d\n", error);

  return 0;
}

#if 0
#include <errno.h>
#include <stdio.h>
#include <string.h>

int foo(const char *filename)
{
  FILE *fp = fopen("a.txt", "r");
  if (fp == NULL)
  {
    return -1;
  }

  if (fp == NULL)
  {
    return -ENOENT;
  }

  return 0;
}

// errno: 에러의 원인을 파악할 수 있는 전역 변수 입니다.     / errno.h
// strerror: 에러의 번호가 어떤 원인인지 문자열로 반환합니다. / string.h
// perror: 에러의 원인을 출력해줍니다.                   / stdio.h

int main(void)
{
  FILE *fp = fopen("a.txt", "r");
  if (fp == NULL)
  {
    // fprintf(stderr, "fopen error: %s\n", strerror(errno));
    perror("fopen error");
    return 1;
  }

  return 0;
}
#endif