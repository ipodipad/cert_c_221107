// 1_전처리기19.c
#include <stdio.h>

#if 0
// 가변인자 매크로
// : 매크로 함수에서 인자를 다양하게 전달받을 수 있는 가변인자를 지원합니다.
// => c99 표준입니다.
#define TRACE(fmt, ...) \
  fprintf(stderr, "%s:%d (%s): " fmt, __FILE__, __LINE__, __func__, __VA_ARGS__);

int main(void)
{
  TRACE("Hello world - %d %d %s\n", 10, 20, "world");
  return 0;
}
#endif