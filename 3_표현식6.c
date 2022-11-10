// 3_표현식6.c
#include <stdio.h>

// 핵심: 포인터 연산이 동작하는 방식을 제대로 이해하지 못한다면,
//      심각한 오류나 버퍼 오버플로우의 문제가 발생할 수 있습니다.

enum
{
  BUF_SIZE = 10
};

// int* cur = buf; // 100
//  = cur + 3;                   // 103 X
//  = cur + (sizeof(*cur) * 3)   // 112

// 포인터를 대상으로 1바이트 단위 연산을 수행하고자 한다면,
// 포인터를 char*로 사용해야 합니다.

int main(void)
{
  int buf[BUF_SIZE];

  int *cur = buf;

/* 잘못된 코드 */
#if 0
  while (cur < (buf + sizeof(buf)))
  {
    *cur = 0;
    cur++;
  }
#endif

  // 해결 방법 1. 1바이트 단위 연산은 포인터를 char*로 캐스팅해야 합니다.
  while ((char *)cur < ((char *)buf + sizeof(buf)))
  {
    *cur = 0;
    cur++;
  }

  cur = buf;
  // 해결 방법 2. 배열을 포인터의 연산으로 사용할 경우, 코드의 가독성이
  //            떨어지고, 실수를 찾기 어렵습니다.
  for (int i = 0; i < BUF_SIZE; i++)
  {
    // *(cur + i) = 0;
    cur[i] = 0;
  }

  for (int i = 0; i < BUF_SIZE; i++)
  {
    printf("%d\n", buf[i]);
  }

  return 0;
}