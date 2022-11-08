// 2_선언1.c

#include <stdio.h>

struct point
{
  int x;
  int y;

  char name[32];
};

// 문제점: 구조체를 call by value로 전달할 경우, 복사의 오버헤드가 있습니다.
// 해결방법
//  => 구조체를 값으로 전달하지 않고, 주소로 전달해야 합니다.
#if 0
void print_point(struct point pt)
{
  printf("%d, %d\n", pt.x, pt.y);
}
#endif

// 변하지 않는 객체는 반드시 const로 보장해야 합니다.
// void print_point(struct point *pt)
void print_point(const struct point *pt)
{
  // printf("%d, %d\n", (*pt).x, (*pt).y);
  printf("%d, %d\n", pt->x, pt->y);

  // pt->x = 100; /* 의도하지 않은 변경 */
}

// 불변성 / 상수 객체 지향해야 합니다.
// => 생성 이후에 값이 변경되지 않습니다.
// => 불변성은 애플리케이션의 정확성과 안정성을 보장하는데 도움이 됩니다.
//  1) 멀티 스레드에서 동기화 이슈가 발생하지 않습니다.
//  2) 참조 계수 등의 자원 공유 모델을 쉽게 구현할 수 있습니다.
//  3) 객체(대상체)의 값이 변경되는 경로를 쉽게 추적할 수 있습니다.

int main(void)
{
  printf("%lu\n", sizeof(struct point));

  struct point pt1 = {10, 20};
  print_point(&pt1);
  print_point(&pt1);

  const struct point ct = {10, 20}; /* 상수 객체(불변 객체) */

  struct point vt = {10, 20}; /* 가변 객체 */

  return 0;
}
