// 0_시작2.c

// 6. C의 문제점
//  1) 미정의 동작
//  => 실행 중인 프로그램의 결과가 예측할 수 없을때마다
//     그것은 미정의 동작을 가지고 있다고 합니다.
#if 0
#include <limits.h>
#include <stdio.h>

int main(void)
{
  int n1 = 5;
  int n2 = 0;

  // int result = n1 / n2; /* 미정의 동작 */

  int x = INT_MAX;
  printf("%d\n", x + 1); /* 미정의 동작 */

  int *p = NULL;
  *p = 42; /* 미정의 동작 */

  return 0;
}
#endif

// 2) 미지정 동작
// => C 프로그램의 표준이 2개 이상의 가능성을 제공하지만,
//    컴파일러의 작성자가 선택해야 하는 요구사항을 제공하지 않을 때
//    "미지정 동작" 이라고 합니다.

#include <stdio.h>

int x = 0;

int func1(void)
{
  x = 2;
  return 2;
}

int func2(void)
{
  x = 1;
  return 1;
}

int main(void)
{
  /* 이항 연산자에서 함수의 호출이 앞에서부터 인지,
     뒤에서부터 인지 지정되지 않았습니다. */
  // int sum = func1() + func2();

  /* 해결 방법 */
  int r2 = func2();
  int r1 = func1();

  int sum = r1 + r2;

  printf("sum: %d\n", sum);

  printf("x: %d\n", x); /* x = 2? x = 1? */

  return 0;
}