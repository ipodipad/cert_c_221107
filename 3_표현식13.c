// 3_표현식13.c
#include <stdio.h>
#include <string.h>

struct X
{
  int a[6];
};

struct X foo(void)
{
  struct X result = {{1, 2, 3, 4, 5, 6}};
  return result;
}

// 구조체를 반환하지 말고, Out Parameter를 사용하는 것이 좋습니다.
void goo(struct X *result)
{
  struct X temp = {{1, 2, 3, 4, 5, 6}};
  memcpy(result, &temp, sizeof(temp));
}

int main(void)
{
  printf("%d\n", ++(foo().a[0])); /* 미정의 동작 */

  int *arr = foo().a;
  printf("%d\n", ++(arr[0])); /* 미정의 동작 */

  /* 해결 방법 */
  struct X result = foo();
  printf("%d\n", ++result.a[0]); /* OK */

  goo(&result);
  printf("%d\n", ++result.a[0]); /* OK */

  return 0;
}