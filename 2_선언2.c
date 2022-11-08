// 2_선언2.c

#include <stdio.h>

#if 0
const int **ipp;
int *ip;
const int i = 42;

//  **       *      int
//  ipp ---> ip ---> i

int main(void)
{
  ipp = &ip;
  *ipp = &i;

  *ip = 100; /* 미정의 동작: const로 지정된 변수를 수정할 때 */

  return 0;
}
#endif

#if 0
// 수정 가능하게 하겠다.
int **ipp;
int *ip;
int i = 42;

//  **       *      int
//  ipp ---> ip ---> i

int main(void)
{
  ipp = &ip;
  *ipp = &i;

  *ip = 100;

  return 0;
}
#endif

#if 0
// 수정 불가능하게 하겠다.
const int **ipp;
const int *ip;
const int i = 42;

//  **       *      int
//  ipp ---> ip ---> i

int main(void)
{
  ipp = &ip;
  *ipp = &i;

  // *ip = 100; /* 컴파일 오류 */

  return 0;
}
#endif

// const 위치
//  1. * 기호의 앞에 존재할 때
//         const
//   p ----> n

//  2. * 기호의 뒤에 존재할 때
//  const
//    p ----> n
int main(void)
{
  int n = 10;
  int x = 20;

  const int *p1 = &n;
  // *p1 = 100; /* Error */
  p1 = &x; /* OK */

  int const *p2 = &n;
  // *p2 = 100; /* Error */
  p2 = &x; /* OK */

  int *const p3 = &n;
  *p3 = 100; /* OK */
  // p3 = &x;   /* Error */

  // const    const
  //   p ----> n
  const int *const p4 = &n;
  // *p4 = 100; /* Error */
  // p4 = &x;   /* Error */

  int const *const p5 = &n;
  // *p5 = 100; /* Error */
  // p5 = &x;   /* Error */

  return 0;
}