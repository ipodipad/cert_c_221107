// 1_전처리기10.c
#include <stdio.h>

// 1. 라인 주석은 역슬래쉬가 가장 마지막에 있을 경우,
//    다음 라인도 주석처리 됩니다.
//  => MISRA, CERT에 라인 주석은 금지되어 있습니다.

// 2. 삼중자
//  ??=  => #
//  ??/  => \
//  => 특정 지역의 문자셋에 C의 핵심적인 문자가 포함되지 않아서
//     사용되었습니다.
//  => ??를 연속으로 사용하면 안됩니다.

// 3. 대다수의 컴파일러는 삼중자가 비활성화되어 있습니다.

// 4. 표준 위원회에서 삼중자를 제외하고자 하는 의견이 있었습니다.
//  =>   C: IBM 반대, 제외되지 않았습니다.
//     C++: C++17, 삼중자가 표준에서 제외되었습니다.

int main(void)
{
  int a = 10;

  // a의 값은 무엇일까요???/
  /* a의 값은 무엇일까요???/ */
  ++a;
  printf("%d\n", a);
  printf("%s\n", "??< ??> ??=");

  return 0;
}