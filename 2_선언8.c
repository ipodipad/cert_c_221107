// 2_선언8.c

int x = 10;
// external linkage: 외부 연결
// => 다른 파일에서 전역 변수에 접근이 가능합니다.

static int a = 100;
// internal linkage: 내부 연결
// => 다른 파일에서 접근이 불가능합니다.

void foo(void);
// 외부 전역 함수 호출을 위한 선언

// $ nm source.o
/*
int x = 10;
static int a = 100;
                 U _foo
0000000000000000 T _main
000000000000001c D _x

int x = 10;
int a = 100;
0000000000000020 D _a
                 U _foo
0000000000000000 T _main
000000000000001c D _x

*/

// C - external linkage
const int c1 = 100;

// C++ - internal linkage
const int c2 = 100;
/*
C
0000000000000020 S _c1
0000000000000024 S _c2

                 U _foo
0000000000000000 T _main
000000000000001c D _x

C++
                 U __Z3foov
0000000000000000 T _main
000000000000001c D _x

*/

int main(void)
{
  foo();
  return 0;
}