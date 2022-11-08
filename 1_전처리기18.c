// 1_전처리기18.c
#include <stdio.h>

#define MORE_ARGS 1

void foo
#if (MORE_ARGS == 1)
    (int a, int b, int c, int d)
#else
    (int a, int b, int c)
#endif
{
#if (MORE_ARGS == 1)
  printf("%d %d %d %d\n", a, b, c, d);
#else
  printf("%d %d %d\n", a, b, c);
#endif
}

#if (MORE_ARGS == 1)
#define CALL_FOO(a, b, c, d) foo(a, b, c, d)
#else
#define CALL_FOO(a, b, c) foo(a, b, c)
#endif

//--------------------
// => 매크로 함수의 인자 목록에서 전처리기 지시어에 대한 사용은 미정의 동작입니다.
//   : C 표준 라이브러리의 많은 함수가 매크로로 제공될 수 있습니다.
//     - memcpy, printf, assert

int main(void)
{
  /* 잘못된 코드 */
  /*
  CALL_FOO(10, 20,
#if (MORE_ARGS == 1)
           30,
#endif
           40);
  */

  /* 해결 방법 */
#if (MORE_ARGS == 1)
  CALL_FOO(10, 20, 30, 40);
#else
  CALL_FOO(10, 20, 40);
#endif

  return 0;
}