// 1_전처리기12.c

#include <stdio.h>

/* 잘못된 코드 */
// #define cstring char *
// 매크로 정의는 타입에 대한 범위 규칙이 제대로 적용되지 않습니다.
//  => 타입을 재정의할 때는 typedef를 이용해야 합니다.
#if 0
typedef char *cstring;

// char *p1, p2;
//   p1 => char*
//   p2 => char

// char *p1, *p2;
//   p1 => char*
//   p2 => char*

int main(void)
{
  /* OK */
  // cstring p1;
  // cstring p2;

  cstring p1, p2; /* NO */
  // char* p1, p2;

  p1 = "Tom";
  printf("%s\n", p1);

  p2 = "Seoul";
  printf("%s\n", p2);

  return 0;
}
#endif

#if 0
// C/C++ 에서 타입을 구하는 방법
//  - 이름(식별자)을 뺀 나머지가 타입입니다.

int main(void)
{
  int a;
  // a의 타입은 무엇입니까?
  // => int

  int x[3] = {10, 20, 30};
  // x의 정확한 타입은 무엇입니까?
  // => int[3]
  // => 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다.
  //   : Decay(부식된다)
  // => Decay 예외
  //   1) sizeof
  //   2) &

  int *p = x;
  // int *p = &x[0];
  printf("%lu\n", sizeof(x));
  printf("%lu\n", sizeof(int[3]));

  // int(*p2)[3] = &x;

  // int[3]* p2 = &x; => 허용 X, 배열의 첨자는 식별자의 뒤에 위치해야 합니다.
  // int *p2[3] = &x; => p2는 [3]이 우선순위가 높기 때문에, 배열이 됩니다. - 포인터 배열
  //                     [ int* ][ int* ][ int* ]

  // int (*p2)[3] => * ----> int[3] - 배열 포인터

  return 0;
}
#endif

#if 0
// int *foo(void)
// 1. foo(void)
//  => foo는 인자 없는 함수입니다. 반환타입은?

// 2. *foo(void)
//  => 반환타입은 포인터 입니다. 가르키는 타입은?

// 3. int *foo(void)
//  => 가르키는 타입은 int입니다.

// 반환 타입은?
int *foo(void)
{
  static int x[3]; // 내부 정적 변수 / 정적 지역 변수
  return x;
  // x -> &x[0] -> int*
}

// int (*goo(void))[3]
// 1. goo(void)
//  => goo는 인자 없는 함수입니다. 반환타입은?

// 2. (*goo(void))
//  => 반환타입은 포인터입니다. 가르키는 타입은?

// 3. (*goo(void))[3]
//  => 가르키는 타입은 3개짜리 배열입니다. 하나의 원소타입은?

// 4. int (*goo(void))[3]
//  => 하나의 원소타입은 int 입니다.

// 반환 타입은?
int(*goo(void))[3]
{
  static int x[3];
  return &x;
  // &x -> int(*)[3]
}

int main(void)
{
  return 0;
}
#endif

// int x[2][3]
// 1. x[2]
// => x는 2개짜리 배열입니다. 한개의 원소타입이?

// 2. x[2][3]
// => 3개짜리 배열입니다. 한개의 원소타입이?

// 3. int x[2][3]
// => 한개의 원소타입이 int 입니다.

#if 0
int (*foo(void))[3]
{
  static int x[2][3];
  // 몇개짜리 배열인가요? 2개
  //  : [ int[3] ][ int[3] ]

  return x; // return &x[0]
  // int(*)[3]
}

// 함수 Decay
// - 함수의 이름은 함수 포인터로 해석됩니다.
int (*(*goo(void))(void))[3]
{
  // return &foo;
  return foo;

  // int (* (*)(void))[3]
}

int add(int a, int b) { return a + b; }
// int(*)(int a, int b) -----> int(int, int)

int main(void)
{
  return 0;
}
#endif

// int a;
// typedef int a;
//  => 변수를 만드는 형태로 타입의 별칭을 지정할 수 있습니다.
typedef int (*PARR3)[3];

// int (*foo(void))[3]
PARR3 foo(void)
{
  static int x[2][3];
  return x;
}

typedef PARR3 (*FP)(void);

// int (*(*goo(void))(void))[3]
FP goo(void)
{
  return &foo;
  // int (*(*)(void))[3]
}

int main(void)
{
  return 0;
}
