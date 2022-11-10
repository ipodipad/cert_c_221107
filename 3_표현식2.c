// 2_표현식2.c

// https://kqueue.org/blog/2012/06/25/more-randomness-or-less/
// 초기화되지 않은 메모리를 시드로 이용합니다.
// 1. 결정되지 않은 값을 접근하는 것은 미정의 동작입니다.
// 2. 컴파일러는 초기화되지 않은 변수의 접근을 최적화하고, 결정적으로
//    예측이 가능할 수 있습니다.
//  => 암호화 같은 예측 불가능성의 의존하는 보안 알고리즘에서 불확실성에 대한 손실은
//     보안에 취약점으로 작용할 수 있습니다.
#if 0
#include <unistd.h>

#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include <stdio.h>

int main(void)
{
  struct timeval tv;
  unsigned long junk;

  gettimeofday(&tv, NULL);

  srand(tv.tv_sec ^ tv.tv_usec ^ junk);
  printf("%d\n", rand());
  printf("%d\n", rand());
  printf("%d\n", rand());

  return 0;
}
#endif

#include <unistd.h>

#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include <stdio.h>

// 지역 변수, 힙 변수(malloc)는 초기화하지 않을 경우,
// 접근하였을 때 미정의 동작이 발생합니다.

int main(void)
{
  struct timeval tv;
  double cpu_time_used;

  cpu_time_used = ((double)clock()) / CLOCKS_PER_SEC;
  gettimeofday(&tv, NULL);

  srand(tv.tv_sec ^ tv.tv_usec ^ (unsigned long)cpu_time_used);
  printf("%d\n", rand());
  printf("%d\n", rand());
  printf("%d\n", rand());

  return 0;
}