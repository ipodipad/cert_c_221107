// 1_전처리기15.c
#include <stdio.h>

// 핵심: 헤더 파일은 반드시 인클루드 가드를 제공해야 합니다.
// => 중복 포함시 문제를 해결할 수 있습니다.

// 타입에 대한 선언은 헤더파일을 통해 제공되어야 합니다.
// => complex.h
#if 0
struct complex
{
  double real;
  double image;
};
#endif

#include "a.h"
#include "complex.h"

#if 0
#ifndef _COMPLEX_H_
#define _COMPLEX_H_
//      __COMPLEX_H__

/**/
#endif
#endif
// 문제점: 예약어를 사용하고 있습니다.
// -> C 표준에서는 예약을 다음과 같이 정의하고 있습니다.
// 1. 밑줄 표시로 시작하고, 두번째 문자가 대문자이거나, 또 다른 밑줄 표시 기호로 시작되는 모든 식별자는 예약어입니다.
// 2. 밑줄 표시로 시작되는 모든 식별자는 파일 범위에서 일반 식별자와 태그 이름을 위해 예약됩니다.
int _g;            /* NO */
void _foo(void) {} /* NO */

struct _goo /* NO */
{
};

enum _e /* NO */
{
  XXX
};

int main(void)
{
  return 0;
}