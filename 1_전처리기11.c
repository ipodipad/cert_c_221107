// 1_전처리기11.c
#include <stdio.h>

// 매크로 함수
// 1. 호출하지 않고, 텍스트 치환하므로 함수 호출 오버헤드가 존재하지 않습니다.
// 2. 타입에 종속적이지 않은 함수를 구현할 수 있습니다.
#if 0
#define ABS(x) ((x) > 0 ? (x) : (-x))

// 인라인 함수로 제공할 때, 아래와 같이 각 타입에 따른 별도의 함수를 제공해야 합니다.
// => C는 오버로딩을 지원하지 않기 때문에, 다른 이름으로 제공해야 합니다.
static inline int iabs(int x)
{
  return x > 0 ? x : -x;
}
static inline double dabs(double x)
{
  return x > 0 ? x : -x;
}

static inline long long llabs(long long x)
{
  return x > 0 ? x : -x;
}

static inline float fabs(float x)
{
  return x > 0 ? x : -x;
}

int main(void)
{
  int n = -10;
  printf("%d\n", ABS(n));
  printf("%d\n", iabs(n));

  // long long l = -1000ll; /* NO */
  long long l = -1000LL;
  printf("%lld\n", ABS(l));
  printf("%lld\n", llabs(l));

  double f = -3.14;
  printf("%lf\n", ABS(f));
  printf("%lf\n", dabs(f));

  float f2 = -5.05F;
  printf("%f\n", ABS(f2));
  printf("%f\n", fabs(f2));

  return 0;
}
#endif

// C11 - _Generic
#define ABS(x) _Generic((x), int             \
                        : iabs(x), long long \
                        : llabs(x), double   \
                        : dabs(x), float     \
                        : fabs(x))

static inline int iabs(int x)
{
  return x > 0 ? x : -x;
}
static inline double dabs(double x)
{
  return x > 0 ? x : -x;
}

static inline long long llabs(long long x)
{
  return x > 0 ? x : -x;
}

static inline float fabs(float x)
{
  return x > 0 ? x : -x;
}

int main(void)
{
  int n = -10;
  printf("%d\n", ABS(n));

  long long l = -1000LL;
  printf("%lld\n", ABS(l));

  double f = -3.14;
  printf("%lf\n", ABS(f));

  float f2 = -5.05F;
  printf("%f\n", ABS(f2));

  return 0;
}