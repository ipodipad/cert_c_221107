// 1_전처리기17.c
#include <stdio.h>

#if 0
#define SWAP(a, b) \
  int tmp = a;     \
  a = b;           \
  b = tmp

int main(void)
{
  int x = 10, y = 20;

  // int tmp; /* Compile Error */

  SWAP(x, y);
  printf("%d %d\n", x, y);

  return 0;
}
#endif

#if 0
#define SWAP(a, b) \
  {                \
    int tmp = a;   \
    a = b;         \
    b = tmp;       \
  }

int main(void)
{
  int x = 10, y = 20;

  int tmp;

  SWAP(x, y) /* 세미콜론을 사용하지 않아도 컴파일 오류가 발생하지 않습니다. */
  printf("%d %d\n", x, y);

  return 0;
}
#endif

#if 0
// 해결방법 1. 복수 구문 매크로 함수는 do {} while(0)로 감싸야 합니다.
//   do {} while (0)
#define SWAP(a, b) \
  do               \
  {                \
    int tmp = a;   \
    a = b;         \
    b = tmp;       \
  } while (0)

int main(void)
{
  int x = 10, y = 20;

  int tmp;

  SWAP(x, y);
  printf("%d %d\n", x, y);

  return 0;
}
#endif

#if 1
// 해결방법 2. GCC/Clang에서 지원하는 방법
#define SWAP(a, b) \
  ({               \
    int tmp = a;   \
    a = b;         \
    b = tmp;       \
  })

int main(void)
{
  int x = 10, y = 20;

  int tmp;

  int result = SWAP(x, y);
  printf("%d %d %d\n", x, y, result);

  return 0;
}
#endif