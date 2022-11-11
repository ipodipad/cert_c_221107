// 4_타입11.c
#include <stdio.h>

// 부동 소수점
// 1.       float: 32bit
// 2.      double: 64bit
// 3. long double: 128bit

// C99에서 부동 소수점 타입에 대한 요구사항을 플랫폼에서 어떻게 지원해야 하는지
// 명시하고 있지만, 부동 소수점을 구현한 플랫폼자체에서 제대로 구현하고 있지 않습니다.
// => 특정 부동 소수점 표현 방식을 보장할 수 없습니다.

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