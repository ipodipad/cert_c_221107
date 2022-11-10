// 3_표현식1.c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

// 다른 타입의 함수를 함수 포인터에 담아서 호출할 경우
// 미정의 동작이 발생합니다.

int main(void)
{
  int (*fp)(int a, int b);

  fp = &add;
  printf("%d\n", (*fp)(10, 20));

  fp = &sub;
  printf("%d\n", (*fp)(10, 20));

  // 함수의 이름은 함수 포인터로 해석됩니다.
  fp = add;
  // 함수 포인터에 대한 호출은 명시적인 참조를 생략할 수 있습니다.
  printf("%d\n", fp(10, 20));

  fp = sub;
  printf("%d\n", fp(10, 20));

  int (*fp2)(int a, int b, int c);
  fp2 = &add;

  printf("fp2: %d\n", (*fp2)(10, 20, 30)); /* 미정의 동작 */

  return 0;
}