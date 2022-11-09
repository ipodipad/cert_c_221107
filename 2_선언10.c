// 2_선언10.c
#include <stdio.h>

// 문제점: 수명이 끝난 변수의 주소를 참조하는 문제가 있습니다.
enum
{
  ARRAY_SIZE = 10
};

// 전역 변수
// char local[ARRAY_SIZE];

void init_array(char **ptr_param)
{
  // 잘못된 코드
  // char local[ARRAY_SIZE];

  // 내부 정적 변수: 함수가 처음 호출되는 시점에 생성되고,
  //              함수가 더 이상 호출되지 않는 시점까지 유지된다.
  static char local[ARRAY_SIZE];

  for (int i = 0; i < 10; ++i)
  {
    local[i] = i + 1;
  }

  *ptr_param = local;
}

int main(void)
{
  char *ptr;
  init_array(&ptr);

  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    printf("%d\n", ptr[i]);
  }

  return 0;
}