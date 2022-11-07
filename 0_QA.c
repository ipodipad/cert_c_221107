// 0_QA.c

#if 0
int main(void)
{
  int nRetry = 5;
  // while (nRetry--) /* NO */

  while (nRetry-- > 0) /* OK */
  {
  }

  return 0;
}
#endif

// C++안에서의 C의 표준과, C의 표준은 다릅니다.
#include <stdio.h>

void foo(void) {} /* OK */
void goo() {}     /* NO */

int main(void)
{
  goo(10, 20); /* 컴파일 오류가 발생하지 않습니다. */
  // foo(10, 20); /* 컴파일 오류 */
  printf("main\n");

  void (*fp1)(void);
  fp1 = foo;

  // fp1(10, 20); /* 컴파일 오류 */

  void (*fp2)();
  fp2 = foo;

  fp2(10, 20); /* 컴파일 오류가 발생하지 않습니다. */

  return 0;
}