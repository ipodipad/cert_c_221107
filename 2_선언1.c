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

int main(void)
{
  printf("%lu\n", sizeof(struct point));

  struct point pt1 = {10, 20};
  print_point(&pt1);
  print_point(&pt1);

  return 0;
}