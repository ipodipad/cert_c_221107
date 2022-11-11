// 4_타입3.c
#include <stdio.h>
#include <string.h>

// * char 타입
//   char: 문자열 리터럴의 각 요소를 구성하는 타입입니다.
//    signed / unsigned 미지정 사항입니다.
//  => 컴파일러의 구현에 따라 달라집니다.

//          char: 문자 타입
//   signed char: 부호 있는 8비트 정수 타입
// unsigned char: 부호 없는 8비트 정수 타입

// 핵심: 문자 타입이 signed인지 unsigned인지 가정해서 코드를 작성하면 안됩니다.
//      정수 타입을 기반으로 사용할 경우, 반드시 signed / unsigned 명시해야 합니다.

int main(void)
{
  char c = 100;

  signed char str1[] = "hello world";   /* NO */
  unsigned char str2[] = "hello world"; /* NO */
  char str[] = "hello world";           /* OK */

  strlen(str1);
  strlen(str2);

  return 0;
}