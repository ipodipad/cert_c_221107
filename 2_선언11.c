// 2_선언11.c
#include <stdio.h>

#if 1
// 핵심: 중복 가시성을 갖는 동일한 이름공간의 식별자는
//      타입포그라피적으로 모호하지 않아야 한다.
int main(void)
{
  int id_a_b_c;
  int id_abc;
  int id_abc;
  int id_ABC;

  int id_I;
  int id_1;
  int id_l;

  int id_Z;
  int id_2;

  int id_0;
  int id_O;

  int id_8;
  int id_B;

  // int id_rn;
  // int id_m;

  /* 예외 */
  int id_rn;
  struct
  {
    int id_m;
  } xxx;

  xxx.id_m = 123;

  return 0;
}
#endif

void foo()
{
} /* NO */
void goo(void) {} /* OK */

// K&R Style - 사용하면 안됩니다.
/*
int max(a, b)
int a, b;
{
  return a > b ? a : b;
}
*/

int max(int a, int b)
{
  return a > b ? a : b;
}

// header
extern int max(int, int);     /* NO */
extern int max(int a, int b); /* OK */

int main(void)
{
  void (*f1)(int, int) = max;     /* NO */
  void (*f2)(int a, int b) = max; /* OK */

  void (*f3)() = foo;     /* NO */
  void (*f4)(void) = foo; /* OK */

  // foo(10, 20); /* 컴파일 오류가 발생하지 않습니다. */
  // goo(10, 20); /* 컴파일 오류 */

  int result = max(10, 20);
  printf("result: %d\n", result);

  return 0;
}
