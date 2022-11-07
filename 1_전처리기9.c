// 1_전처리기9.c
#include <stdio.h>

// 예외 3. 상수 표현식이 필요할 때
//   => 인라인 함수를 사용할 수 없습니다.

#define DIV2(x) ((x) / 2)

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