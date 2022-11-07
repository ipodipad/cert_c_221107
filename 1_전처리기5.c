// 1_전처리기5.c
#if 0
#include <stdio.h>

int cnt = 0;

// 지역 변수 cnt 변수를 만들면 안됩니다.
#define CALL_FUNC(fp) (++cnt, fp())
// => 매크로 함수를 인라인 함수로 변경해야 합니다.

void print_cnt(void)
{
  printf("cnt = %d\n", cnt);
}

int main(void)
{
  int cnt = 10; /* 지역 변수 */

  CALL_FUNC(print_cnt); // (++cnt, print_cnt())
  CALL_FUNC(print_cnt); // (++cnt, print_cnt())
  CALL_FUNC(print_cnt); // (++cnt, print_cnt())

  return 0;
}
#endif

#include <stdio.h>

int cnt = 0;

// 지역 변수 cnt 변수를 만들면 안됩니다.
#define CALL_FUNC(fp) (++cnt, fp())

// => 매크로 함수를 인라인 함수로 변경해야 합니다.
static inline void call_func(void (*fp)(void))
{
  ++cnt;
  fp();
}

void print_cnt(void)
{
  printf("cnt = %d\n", cnt);
}

int main(void)
{
  int cnt = 10; /* 지역 변수 */

  call_func(print_cnt);
  call_func(print_cnt);
  call_func(print_cnt);

  return 0;
}