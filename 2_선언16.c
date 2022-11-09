// 2_선언16.c
#include <stdio.h>

#include "user.h"

// $ nm user.o
/*
0000000000000064 D _current
0000000000000000 T _debug_print
0000000000000030 T _get_current_user
0000000000000040 T _print_user
                 U _printf


0000000000000034 d _current
0000000000000000 T _get_current_user
0000000000000010 T _print_user
                 U _printf

*/

// 1. 외부에서 접근하면 안되는 전역 변수와 전역 함수에 대해서는
//    반드시 static으로 만들어야 합니다.

// 2. 객체(변수) 또는 함수의 가시성을 제한하면 실수 또는 악의적인 접근의
//    위험성을 줄일 수 있습니다.

// 3. 전역 이름 공간의 이름 충돌을 방지할 수 있습니다.

struct user
{
  char a[32];
  char b[32];
};

extern USER current;
extern void debug_print(USER *p);

int main(void)
{
  /* 링크 오류 */
  printf("%s %s\n", current.a, current.b);

  USER *user = get_current_user();

  /* 링크 오류 */
  debug_print(user);

  print_user(user);

  // printf("%s\n", user->password); /* Compile Error */

  return 0;
}