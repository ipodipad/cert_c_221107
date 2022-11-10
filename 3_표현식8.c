// 3_표현식8.c
#if 0
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

  // 배열의 끝 다음까지만 허용됩니다.
  int *p3 = p2 + 1; /* 미정의 동작 */

  return 0;
}
#endif

// 18.2 포인터 사이의 뺄셈은 동일한 배열의 요소를 주소로 지정하는 포인터에 대해서만
//      사용해야 합니다.
//  => 오프셋을 구하는 연산으로 사용됩니다.

#include <stdio.h>

int main(void)
{
  //           a1             p1
  int a1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int a2[10];

  int *p1 = a1 + 5;
  int *p2 = a2 + 5;

  printf("%ld\n", a1 - p1); // OK, -5 => 요소 5개 앞에 존재한다.
  printf("%ld\n", p1 - a1); // OK,  5 => 요소 5개 뒤에 존재한다.

  printf("%ld\n", p1 - p2); /* 허용되지 않는 연산 */

  return 0;
}