// 1_전처리기1.c

#include <stdio.h>

// 1. C 프로그램이 빌드되는 과정
//  => 전처리기(preprocessor) => 컴파일(Compile) => 링크(Link) => a.exe / a.out
//     #define / #include     단위: 파일          a.o + b.o
//     #if / #ifdef ..       a.c => a.o / a.obj
//       "텍스트 처리"          b.c => b.o / b.obj

// 2. godbolt.org
#define PI 3.14

// 3. 함수를 호출할 때는, 직접 코드를 작성하는 것에 비해
//    오버헤드가 있습니다.
int square(int x) { return x * x; }

// 4. 함수 호출 오버헤드를 제거하기 위해서, 매크로 함수를 사용합니다.
//  => 이름은 대문자로 제공해야 합니다.
/* 잘못된 코드 */
// #define SQUARE(x) x * x

// 5. 매크로 함수를 작성할 때, 반드시 매개 변수에 괄호를 사용해야 합니다.
//  => 우선순위에서 문제가 발생할 수 있습니다.

#define SQUARE(x) (x) * (x)

int main(void)
{
  printf("pi: %lf\n", PI);

  int x = 10;
  int result1 = x * x;
  int result2 = square(x);
  int result3 = SQUARE(x);

  int result4 = square(x + x);
  int result5 = SQUARE(x + x);
  /*            x + x * x + x; */

  printf("result1: %d\n", result1);
  printf("result2: %d\n", result2);
  printf("result3: %d\n", result3);

  printf("result4: %d\n", result4);
  printf("result5: %d\n", result5);

  return 0;
}