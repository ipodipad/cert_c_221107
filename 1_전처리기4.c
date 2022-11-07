// 1_전처리기4.c

// 1. 매크로 함수
//  -> 일반 함수가 수없이 호출될 때, 함수 호출의 오버헤드를 제거해서
//     최적화할 수 있습니다.

// 2. 변수(대상체)의 값이 변한다 => 부수 효과(Side Effect)

// 3. 하나의 표현식안에서 같은 대상체에 대한 두번 이상의 부수 효과는
//    미정의 동작입니다.
//   => 컴파일러의 구현에 따라 결과가 다릅니다.

#include <stdio.h>

// 4. 매크로 함수로 전달된 파라미터가, 매크로 치환 영역에서 2번 이상 치환될 때
//    미정의 동작이 발생할 수 있습니다.
//    => 매크로 함수에서는 해결이 불가능합니다.
#if 0
#define SQR(x) ((x) * (x))
#define ABS(x) ((x) > 0 ? (x) : -(x))

int main(void)
{
  int x = 2;
  // printf("%d\n", SQR(++x)); /* 미정의 동작 */
  //             (++x) * (++x)
  //            : multiple unsequenced modifications to 'x'

  int a = -10;
  printf("%d\n", ABS(--a)); /* 미정의 동작 */
  //              ((--a) > 0 ? (--a) : -(--a))

  return 0;
}
#endif

#if 0
// 해결 방법 1.
// 1. 매크로 함수의 매개 변수에 대해서 증가 또는 감소를 불완전한 매크로 함수
//    이전에 수행해야 합니다.
// 2. 매크로 함수의 이름에 안전하지 않음을 알립니다.
#define UNSAFE_SQR(x) ((x) * (x))
#define UNSAFE_ABS(x) ((x) > 0 ? (x) : -(x))

int main(void)
{
  int x = 2;
  ++x;
  printf("%d\n", UNSAFE_SQR(x));

  int a = -10;
  --a;
  printf("%d\n", UNSAFE_ABS(a));

  return 0;
}
#endif

// 해결 방법 2.
//  => C99 표준에서 새롭게 도입된 문법이 있습니다.
//  => inline 함수
//  C++
//   inline void foo(void) {}
//  C
//   static inline void foo(void) {}

//  => 인라인 함수는 함수 호출을 수행하지 않고, 함수 본문으로 기계어 치환을
//     수행합니다.
//  => 인라인 최적화는 컴파일 최적화 명령입니다.
//     사용자가 inline 키워드를 사용해도, 무조건 인라인화가 수행되지 않습니다.
//     MSVC: /Ob1

static inline int square(int x) { return x * x; }
static inline int abs(int x) { return x > 0 ? x : -x; }

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) > 0 ? (x) : -(x))

int main(void)
{
  int x = 2;
  printf("%d\n", square(++x));
  /*
          mov     eax, DWORD PTR x$[rsp]
          imul    eax, DWORD PTR x$[rsp]
          mov     edx, eax
          lea     rcx, OFFSET FLAT:$SG6987
          call    printf
  */
  printf("%d\n", SQR(x));
  /*
          mov     eax, DWORD PTR x$[rsp]
          imul    eax, DWORD PTR x$[rsp]
          mov     edx, eax
          lea     rcx, OFFSET FLAT:$SG6988
          call    printf
  */

  int a = -10;
  printf("%d\n", abs(--a));
  printf("%d\n", ABS(a));

  return 0;
}