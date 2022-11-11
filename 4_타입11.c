// 4_타입11.c
#include <stdio.h>

// 부동 소수점
// 1.       float: 32bit
// 2.      double: 64bit
// 3. long double: 128bit

// C99에서 부동 소수점 타입에 대한 요구사항을 플랫폼에서 어떻게 지원해야 하는지
// 명시하고 있지만, 부동 소수점을 구현한 플랫폼자체에서 제대로 구현하고 있지 않습니다.
// => 특정 부동 소수점 표현 방식을 보장할 수 없습니다.

#if 0
int main(void)
{
  printf("%lu\n", sizeof(float));
  printf("%lu\n", sizeof(double));
  printf("%lu\n", sizeof(long double));

  float f = 3.14F;        // => %f
  double d = 3.14;        // => %lf
  long double ld = 3.14L; // => %Lf

  printf("%f %lf %Lf\n", f, d, ld);

  return 0;
}
#endif

#if 0
int main(void)
{
  int i = 10;
  long l = 10L;
  long long ll = 10LL;

  printf("%d %ld %lld\n", i, l, ll);

  size_t s = 100;
  printf("%zu\n", s); // size_t

  return 0;
}
#endif

#include <inttypes.h>
#include <stdint.h>

int main(void)
{
  int8_t a = 10;
  int16_t b = 10;
  int32_t c = 10;
  int64_t d = 10LL;

  printf("%" PRId8, a);
  printf("%" PRId16, b);
  printf("%" PRId32, c);
  printf("%" PRId64, d);

  printf("%p\n", &a);

  return 0;
}
