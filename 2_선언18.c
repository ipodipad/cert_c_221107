// 2_선언18.c
#include <stdio.h>
#include <string.h> // memcpy / memmove

// $ gcc source.c
// memcpy
//  => 1 1 2 2 4 4 0 0 0 0
//   gcc source.c -O2
//  => 1 1 2 3 4 4 0 0 0 0

// $ gcc source.c
// memmove
//  => 1 2 3 4 5 0 0 0 0 0
//  => 1 1 2 3 4 5 0 0 0 0

//   memcpy(void *restrict dst, const void *restrict src, size_t n);
//   > restrict로 한정된 포인터를 인자로 전달 받습니다.
//     인자로 전달된 dest와 src를 통해 동일한 영역에 참조가 발생하면,
//     미정의 동작이 발생합니다.

//   memmove(void *dst, const void *src, size_t len);
//  > memcpy와 동일한 동작을 수행하지만, memcpy의 경우 restrict 최적화에 의해 더 빠르게 동작합니다.
//    중첩된 영역에서 memcpy를 사용할 수 없기 때문에, memmove를 이용해야 합니다.

#if 0
int main(void)
{
  //                 |xxxxxxxxx--| dest
  //             |----xxxxxxxxx| src
  int data[10] = {1, 2, 3, 4, 5};

  for (int i = 0; i < 10; ++i)
  {
    printf("%d ", data[i]);
  }
  printf("\n");

  // memcpy(data + 1, data, sizeof(int) * 5);
  memmove(data + 1, data, sizeof(int) * 5);

  for (int i = 0; i < 10; ++i)
  {
    printf("%d ", data[i]);
  }
  printf("\n");

  return 0;
}
#endif

// cvr 한정자
// - const
// - volatile
// - restrict

// restrict 한정자
//  : C99에서 추가된 키워드입니다.
//    포인터가 가리키는 영역에서 "같은 메모리 공간을 참조하지 않는다"라는 한정자로써
//    컴파일러가 최적화에 사용합니다.
//  => 최적화 옵션이 적용되어야 합니다.
//    MSVC: /O2
//     GCC: -O2

// 원인
// - 같은 영역을 전달하면, 미정의 동작이 발생합니다.

// 표준 라이브러리 사용자
// => restrict 키워드가 존재하면, 파라미터를 통해 전달되는 포인터의 영역이 겹치지 않음을 보장해야 합니다.
// "메모리 겹치는 영역이 발생하면, 별도의 에러나 경고가 발생하지 않습니다. 이에 대한 책임은 프로그래머에게 있습니다."
//  : 미정의 동작

// => MISRA:2012
//  : restrict를 사용하지 말라.

void inc1(int *a, int *b, int *x)
{
  // a -> 레지스터
  // x -> 레지스터
  *a += *x;

  // b -> 레지스터
  // x -> 레지스터
  *b += *x;
}
/*
inc1    PROC                                            ; COMDAT
        mov     eax, DWORD PTR [r8]
        add     DWORD PTR [rcx], eax
        mov     eax, DWORD PTR [r8]
        add     DWORD PTR [rdx], eax
        ret     0
inc1    ENDP
*/

// restrict: 최적화 옵션에서 다른 기계어 코드가 만들어집니다.
void inc2(int *restrict a, int *restrict b, int *restrict x)
{
  // a -> 레지스터 1
  // x -> 레지스터 1
  *a += *x;

  // b -> 레지스터 2
  *b += *x;
}
/*
inc2    PROC                                            ; COMDAT
        mov     eax, DWORD PTR [r8]
        add     DWORD PTR [rcx], eax
        add     DWORD PTR [rdx], eax
        ret     0
inc2    ENDP

*/

int main(void)
{
  int a;

  a = 1;
  inc1(&a, &a, &a);
  printf("%d\n", a);

  a = 1;
  inc2(&a, &a, &a);
  printf("%d\n", a);

  return 0;
}
