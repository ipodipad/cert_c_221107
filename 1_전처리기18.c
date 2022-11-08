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

int main(void)
{
  CALL_FOO(10, 20,
#if (MORE_ARGS == 1)
           30,
#endif
           40);

  return 0;
}