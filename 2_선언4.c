// 2_선언4.c
#if 0
#include <stdio.h>

#define SWAP(a, b) \
  do               \
  {                \
    int tmp = a;   \
    a = b;         \
    b = tmp;       \
  } while (0)

int main(void)
{
  double a = 3.14;
  double b = 20.8;

  SWAP(a, b);
  printf("%lf %lf\n", a, b);

  return 0;
}
#endif

#include <stdio.h>

// 매크로 함수의 인자로 전달되는 심볼과 매크로 함수 내부의 심볼이 충돌날 때
// 예상하지 못한 결과가 발생할 수 있습니다.
//  해결방법: 매크로 함수 내부의 심볼이 충돌 가능성이 낮은 이름을 사용해야 합니다.

#if 0
#define SWAP(type, a, b) \
  do                     \
  {                      \
    type tmp = a;        \
    a = b;               \
    b = tmp;             \
  } while (0)
#endif

#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)
#define UNIQUE_NAME(name) CONCAT(name, __LINE__)

int UNIQUE_NAME(a);

#if 0
#define SWAP(type, a, b) \
  do                     \
  {                      \
    type __tmp = a;      \
    a = b;               \
    b = __tmp;           \
  } while (0)
#endif

#define SWAP(type, a, b) \
  do                     \
  {                      \
    type __tmp = a;      \
    a = b;               \
    b = __tmp;           \
  } while (0)

int main(void)
{
  int tmp = 10;
  int b = 20;

  SWAP(int, tmp, b);
  // do { int tmp = tmp; tmp = b; b = tmp; } while (0);     => NO
  // do { int __tmp = tmp; tmp = b; b = __tmp; } while (0); => OK

  printf("%d %d\n", tmp, b);

  return 0;
}