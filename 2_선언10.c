// 2_선언10.c
#include <stdio.h>

// 문제점: 수명이 끝난 변수의 주소를 참조하는 문제가 있습니다.
//     "미정의 동작"
enum
{
  ARRAY_SIZE = 10
};

// 전역 변수
// char local[ARRAY_SIZE];
#if 0
void init_array(char **ptr_param)
{
  // 잘못된 코드
  // char local[ARRAY_SIZE];

  // 내부 정적 변수: 함수가 처음 호출되는 시점에 생성되고,
  //              함수가 더 이상 호출되지 않는 시점까지 유지된다.
  static char local[ARRAY_SIZE];

  for (int i = 0; i < 10; ++i)
  {
    local[i] = i + 1;
  }

  *ptr_param = local;
}

int main(void)
{
  char *ptr;
  init_array(&ptr);

  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    printf("%d\n", ptr[i]);
  }

  return 0;
}
#endif

#if 0
// 함수가 전역 변수나 정적 변수를 사용하는 경우, 재진입이 불가능합니다.
// => 스레드 안정성도 제공되지 않습니다.
//  "멀티 스레드에서 동기화가 필요합니다."
//  : strtok
//   => 재진입이 불가능한 표준 라이브러리 함수

char *init_array(void)
{
  static char local[ARRAY_SIZE];

  for (int i = 0; i < 10; ++i)
  {
    local[i] = i + 1;
  }

  return local; // return &local[0];
}

int main(void)
{
  char *ptr;
  ptr = init_array();

  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    printf("%d\n", ptr[i]);
  }

  return 0;
}
#endif

// > 배열을 함수의 인자로 전달할 때,
//   배열의 길이를 반드시 추가적으로 전달해야 합니다.
// => 길이 정보가 함수 안에서는 알 수 없습니다.

// void init_array(char data[])
// void init_array(char data[10])

// 하나의 원소가 char인 모든 1차원 배열이 사용할 수 있는 함수입니다.
#if 0
void init_array(char *data, int len)
{
  printf("sizeof: %lu\n", sizeof(data));

  for (int i = 0; i < len; ++i)
  {
    data[i] = i + 1;
  }
}

// char[10] 배열만 사용할 수 있는 함수입니다.
void init_array2(char (*p)[10])
{
  printf("sizeof(p): %lu\n", sizeof(p));
  printf("sizeof(*p): %lu\n", sizeof(*p));

  int len = sizeof(*p) / sizeof((*p)[0]);
  for (int i = 0; i < len; ++i)
  {
    (*p)[i] = i + 1;
  }
}

int main(void)
{
  char data[10];
  init_array(data, sizeof(data) / sizeof(data[0])); // init_array(&data[0]);

  init_array2(&data);

  return 0;
}
#endif

#if 1
// 원소 타입이 int인 모든 1차원 배열이 사용할 수 있는 함수입니다.
void init_array(int *data, int len)
{
  for (int i = 0; i < len; ++i)
  {
    data[i] = i + 1;
  }
}

// 하나의 원소 타입이 int[3]인 모든 2차원 배열이 사용할 수 있는 함수입니다.
void init_array2(int (*x)[3], int len)
{
  for (int i = 0; i < len; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      x[i][j] = i + j + 1;
    }
  }
}

int main(void)
{
  int x[2][3];
  init_array2(x, sizeof(x) / sizeof(x[0]));
  // [ int[3] ][ int[3] ]

  int x2[5][3];
  init_array2(x2, 5);

  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      x[i][j] = i + j + 1;
    }
  }

  int a[3];

  for (int i = 0; i < 3; ++i)
  {
    a[i] = i + 1;
  }
  init_array(a, 3);

  return 0;
}
#endif

#if 0
// strtok
// => 문자열 토큰을 분리하는 함수입니다.
//  재진입이 불가능한 함수를 재진입 가능하게 사용하는 방법
//  1) Windows
//    : TLS(Thread Local Storage)
//    => 윈도우에서는 스레드 안전성을 가지므로, 안전하게 사용할 수 있습니다.

//  2) Linux
//    : 재진입 가능한 함수를 제공합니다.
//      strtok_r

#include <string.h>

int main(void)
{
  char str[100] = "hello world show me the money";
  char *last;

  for (char *p = strtok_r(str, " ", &last); p != NULL; p = strtok_r(NULL, " ", &last))
  {
    printf("%s\n", p);
  }

#if 0
  char *p = strtok(str, " ");
  printf("%s\n", p);

  p = strtok(NULL, " ");
  printf("%s\n", p);

  p = strtok(NULL, " ");
  printf("%s\n", p);

  p = strtok(NULL, " ");
  printf("%s\n", p);
#endif

  return 0;
}
#endif

struct point
{
  int x;
  int y;
};

#if 0
/* 지역 변수의 주소를 반환함으로 미정의 동작이 발생합니다. */
struct point *create_point(int x, int y)
{
  struct point pt = {x, y};
  return &pt;
}
#endif

// 해결 방법 1: 전역/정적 변수
//   => 재진입이 불가능합니다.
//      스레드 안전하지 않음.
//   : strtok, readdir ...
#if 0
struct point *create_point(int x, int y)
{
  static struct point pt;

  pt.x = x;
  pt.y = y;

  return &pt;
}
#endif

#include <stdlib.h>
#include <string.h>

// 해결 방법 2. malloc
// 1) free 하지 않으면 메모리 누수가 발생합니다.
// 2) 사용에 제한이 있습니다. MISRA:2012
// => strdup
struct point *create_point(int x, int y)
{
  struct point *pt = (struct point *)malloc(sizeof(struct point));

  if (pt == NULL)
  {
    return NULL;
  }

  pt->x = x;
  pt->y = y;

  return pt;
}

// C언어가 권장하는 방법
// => Out Parameter
void create_point2(int x, int y, struct point *result)
{
  result->x = x;
  result->y = y;
}

int main(void)
{
  // 사용자가 수명을 직접 관리하는 방식이 C에서 많이 사용됩니다.
  struct point pt;
  create_point2(10, 20, &pt);
  //-------------------------

  char str[100] = "hello";

  // char* s = (char*)malloc(strlen(str) + 1);
  // strcpy(s, str);
  char *s = strdup(str);
  free(s); // !!!

  struct point *pt1 = create_point(10, 20);
  printf("%d %d\n", pt1->x, pt1->y);

  struct point *pt2 = create_point(20, 30);

  printf("%d %d\n", pt1->x, pt1->y);

  free(pt1);
  free(pt2);

  return 0;
}
