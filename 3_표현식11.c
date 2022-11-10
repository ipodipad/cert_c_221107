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

  // func(i++, i); /* 미정의 동작 */

  func(i, i);
  ++i;

  return 0;
}
#endif

#if 0
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

#if 0
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
#endif

#if 0
struct AAA
{
  void (*f)(struct AAA *p);
};

void foo(struct AAA *p)
{
  printf("foo\n");
}

void goo(struct AAA *p)
{
  printf("goo\n");
}

struct AAA *g(struct AAA *p)
{
  p->f = goo;
  return p;
}

int main(void)
{
  struct AAA aaa = {foo};
  aaa.f(NULL); // foo

  /* 해결 방법 */
  struct AAA *r = g(&aaa);
  aaa.f(r); // goo

  // g(&aaa)의 결과로 f가 goo로 바뀐 호출이 될지,
  // 바뀌기 이전의 f인 foo가 호출될지 미지정 동작입니다.
  aaa.f = foo;
  aaa.f(g(&aaa)); /* 미지정 동작 */
}
#endif

#if 1
int global = 0;
int f1(void)
{
  global = 10;
  return 10;
}

int f2(void)
{
  global = 20;
  return 20;
}

int main(void)
{
  // int r1 = f1() + f2(); /* 이항 연산자(+, -, *, /) - 미지정 동작 */
  int r_f1 = f1();
  int r_f2 = f2();
  int r1 = r_f1 + r_f2;

  printf("r1: %d\n", r1);
  printf("global: %d\n", global);

  int r2 = f1() && f2();    /* OK, f1() -> f2() 표준 지정되어 있습니다. */
  int r3 = f1() || f2();    /* OK */
  int r4 = (f1(), f2());    /* OK, 나열 연산자도 순서가 지정되어 있습니다. */
  int r5 = f1() ? f2() : 0; /* OK, 삼항 연산자도 순서가 지정되어 있습니다. */

  return 0;
}
#endif