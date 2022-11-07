// 1_전처리기5.c

#include <stdio.h>

int cnt = 0;

// 지역 변수 cnt 변수를 만들면 안됩니다.
#define CALL_FUNC(fp) (++cnt, fp())

void print_cnt(void)
{
  printf("cnt = %d\n", cnt);
}

int main(void)
{
  int cnt = 10; /* 지역 변수 */

  CALL_FUNC(print_cnt);
  CALL_FUNC(print_cnt);
  CALL_FUNC(print_cnt);

  return 0;
}