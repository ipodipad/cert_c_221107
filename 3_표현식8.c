// 3_표현식8.c

#include <stdio.h>

int main(void)
{
  //            p1                              p2
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int *p1 = arr;      /* OK */
  int *p2 = arr + 10; /* OK, Past the end */
  // int *p2 = &arr[10];

  // 배열의 끝을 넘은 다음 요소를 주소로 가르키는 것은 허용됩니다.
  // 하지만 끝 다음 요소에 읽기/쓰기 연산은 미정의 동작입니다.

  while (p1 < p2)
  {
    printf("%d\n", *p1);
    ++p1;
  }

  // *p2 = 10;            /* 미정의 동작 */
  // printf("%d\n", *p2); /* 미정의 동작 */

  return 0;
}