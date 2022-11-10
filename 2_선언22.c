// 2_선언22.c

#include <stdio.h>
#include <string.h>

//   char *strchr(const char *s, int c);
//  => 표준 라이브러리 함수는 함수 인수를 참조하지만, 비상수 포인터를 반환하도록 설계되어
//     있습니다.
//  주의: 상수 인수를 전달할 경우, 반환되는 포인터를 통해 상수 메모리를 수정할 경우
//      미정의 동작이 발생합니다.

int main(void)
{
  // char *s = "hello";
  const char *s = "hello";
  // 상수 문자열은 const char*를 통해 참조되어야 합니다.

  const char *p = strchr(s, 'e');
  // 상수 문자열을 전달한 결과는 상수 포인터를 통해 참조해야 합니다.
  if (p != NULL)
  {
    printf("%c\n", *p);
    // *p = 'x'; /* 미정의 동작 */
  }

  char s2[] = "hello";
  char *p2 = strchr(s2, 'e');
  if (p2 != NULL)
  {
    *p2 = 'x';
    printf("%s\n", s2);
  }

  return 0;
}