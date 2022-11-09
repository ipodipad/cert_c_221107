// 2_선언11.c
#include <stdio.h>

// 핵심: 중복 가시성을 갖는 동일한 이름공간의 식별자는
//      타입포그라피적으로 모호하지 않아야 한다.
int main(void)
{
  int id_a_b_c;
  int id_abc;
  int id_abc;
  int id_ABC;

  int id_I;
  int id_1;
  int id_l;

  int id_Z;
  int id_2;

  int id_0;
  int id_O;

  int id_8;
  int id_B;

  // int id_rn;
  // int id_m;

  /* 예외 */
  int id_rn;
  struct
  {
    int id_m;
  } xxx;

  xxx.id_m = 123;

  return 0;
}