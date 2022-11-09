// 2_선언13.c
#include <stdio.h>

// 가변 인자 매크로 - C99
// 가변 인자 함수
//  - printf, scanf
//   int printf(const char *fmt, ...)
//              <고정 인자>       <가변 인자>

#if 0
int main(void)
{
  printf("hello\n");
  printf("hello: %d\n", 42);
  printf("hello: %d %c\n", 42, 'A');

  return 0;
}
#endif

// 1. C에서 가변인자 함수를 정의하기 위해서는
//    반드시 고정인자가 1개 제공되어야 합니다.
//    => C++은 허용됩니다.

// 2. 가변 인자 함수는 함수의 작성자와 함수의 사용자간의 암묵적 계약을 정의해서
//    함수가 특정 호출에서 전달된 인자의 수를 결정할 수 있도록 합니다.

// 3. 가변 인자를 처리하는 다양한 매크로를 stdarg.h를 통해서 제공됩니다.
//    - va_list
//    - va_start
//    - va_arg
//    - va_end

// 4. 가변 인자를 통해 전달되는 인자의 타입을 알 수 없습니다.
//  => 암묵적 약속이 필요합니다.
#if 0
#include <stdarg.h>

// 구현 방법 1. 마지막에 VA_END가 전달된다.
enum
{
  VA_END = -1
};

int average(int first, ...)
{
  int sum = 0;
  int cnt = 0;

  va_list ap;
  va_start(ap, first); // 초기화

  int i = first;
  while (i != VA_END)
  {
    sum += i;
    ++cnt;

    i = va_arg(ap, int);
  }
  va_end(ap); // 제거

  // 정수를 나누기 연산자(/, %)를 사용할 경우, 미정의 동작이 발생하지 않도록
  // 체크해야 합니다.
  return (cnt != 0) ? sum / cnt : 0;
}

int main(void)
{
  int result;

  result = average(VA_END);
  printf("%d\n", result);

  result = average(10, VA_END);
  printf("%d\n", result);

  result = average(10, 20, VA_END);
  printf("%d\n", result);

  result = average(10, 20, 30, 40, 50, VA_END);
  printf("%d\n", result);

  return 0;
}
#endif
