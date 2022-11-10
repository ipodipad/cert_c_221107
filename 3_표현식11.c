// 3_표현식11.c
#include <stdio.h>

#if 0
void func(int a, int b)
{
  printf("%d %d\n", a, b);
}


int main(void)
{
  int i = 2;

  func(i++, i); /* 미정의 동작 */

  return 0;
}
#endif

void func(int a, int b)
{
  printf("%d %d\n", a, b);
}

int global = 0;

int f1(void)
{
  return global + 10;
}

int f2(void)
{
  global = 100;
  return 20;
}

#if 0
int main(void)
{
  func(f1(), f2()); // 첫번째 인자부터 평가하면, 10, 20
                    // 마지막 인자부터 평가하면, 110, 20
                    /* 미지정 동작 - 함수의 인자로 전달되는 인자의 평가 순서는 미지정 동작입니다. */

  return 0;
}
#endif

#if 0
// 해결 방법
int main(void)
{
  // 명시적으로 순서를 지정해서 호출해야 합니다.
  int r2 = f2();
  int r1 = f1();

  func(r1, r2);

  return 0;
}
#endif

int value(void)
{
  return 10;
}

void foo(int n)
{
  printf("n: %d\n", n);
}

int main(void)
{
  // int ret = value();
  // foo(ret);

  foo(value());

  return 0;
}
