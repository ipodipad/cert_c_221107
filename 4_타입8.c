// 4_타입8.c

#include <stdio.h>

// scanf 계열 함수
//  => 유효하지 않은 값의 입력에 대해서 신뢰성 있는 처리를 할 수 없습니다.
#if 0
int main(void)
{
  int buf;
  printf("Input number: ");

  int ret = scanf("%d", &buf);
  if (ret != 1)
  {
    printf("Input error\n");
  }
  else
  {
    printf("-----> %d\n", buf);
  }

  return 0;
}
#endif

#include <errno.h>

// 해결 방법 1. Linux scanf는 기본 제공하는 추가적인 오류 처리 방법이 있습니다.
//  => 입력 받은 데이터의 길이가 초과된 경우, ERANGE 오류 코드로 처리할 수
//     있습니다.
//  "플랫폼 의존성이 발생할 수 있습니다"
int main(void)
{
  int data;
  if (scanf("%d", &data) != 1)
  {
    printf("error\n");
  }
  else if (ERANGE == errno)
  {
    printf("Out of range\n");
  }
  else
  {
    printf("%d\n", data);
  }

  return 0;
}
