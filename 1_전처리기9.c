// 1_전처리기9.c

#if 0
// 예외 3. 상수 표현식이 필요할 때
//   => 인라인 함수를 사용할 수 없습니다.
#include <stdio.h>

#define DIV2(x) ((x) / 2) /* 컴파일 타임 상수 */

static inline int div2(int x) { return x / 2; }

enum
{
  N1 = DIV2(100),
  // N2 = div2(100) /* Compile Error */
};

void foo(void)
{
  static int x1 = DIV2(100); /* OK */
  // static int x2 = div2(100); /* Compile Error */
}

int main(void)
{

  int x1[DIV2(100)];
  // 배열의 크기는 컴파일 타임에 결정되어야 합니다.

  int x2[div2(100)]; /* Compile Error */

  return 0;
}
#endif

// 예외 4. 매크로 함수에서만 허용되는 문법을 사용할 때
//   => 매크로 함수를 통해서 코드를 생성하는 기술, 도구를 제공합니다.

#include <stdio.h>

#define EVAL_BINOP(OP, L, R) ((L)OP(R))

int main(void)
{
  int a = 100;
  int b = 22;

  printf("%d\n", EVAL_BINOP(+, a, b));
  printf("%d\n", EVAL_BINOP(*, a, b));
  printf("%d\n", EVAL_BINOP(/, a, b));

  return 0;
}
