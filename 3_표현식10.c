
#include <stdio.h>

// EOF
//    Unix: Ctrl + D
// Windows: Ctrl + Z

// 핵심: 실패 가능성이 존재하는 함수에 대해서 반드시 반환값을
//      무시하면 안됩니다.
//      C언어에서 함수가 작업을 성공적으로 수행했는지 여부를 반환값을 통해
//      확인할 수 있습니다.

// 실패 가능성이 없는 함수입니다.
int foo(void)
{
  return 0;
}

int main(void)
{
  int a;
  int b;

  int ret = scanf("%d %d", &a, &b);
  printf("ret: %d\n", ret);

  if (ret == 2)
  {
    printf("%d %d\n", a, b);
  }

  // 결과를 무시할 때는, void 캐스팅을 하면 됩니다.
  // => 명시적으로 함수의 반환값을 무시하는 방법입니다.
  (void)foo();

  return 0;
}
