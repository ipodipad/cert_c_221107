// 1_전처리기8.c

// 예외 2. 조건부 컴파일

//       함수 - ... 가변 인자
//  매크로 함수 - ... Variadic Macro, c99

// $ gcc source.c -DNDEBUG

#define NDEBUG

#include <stdio.h>

#ifndef NDEBUG
#define TRACE(...) fprintf(stderr, __VA_ARGS__)
#else
#define TRACE(...) (void)0

// #define TRACE(...)
// 세미콜론을 사용하지 않아도, 컴파일 오류가 발생하지 않습니다.

// (void) => noop 기계어에서 사라집니다.
#endif

int foo(void)
{
  printf("foo\n");
  return 42;
}

int main(void)
{
  (void)foo();
  // - 결과값을 무시해야 하는 함수에 대해서는, 명시적인 (void) 캐스팅을 통해
  //   반환값을 무시해야 합니다.

  // printf("%d %d %d\n", 10, 20, 30);
  // printf("%d %d\n", 10, 20);

  TRACE("hello\n");
  // fprintf(stderr, "hello\n");

  TRACE("hello: %d %d\n", 10, 20);
  // fprintf(stderr, "hello: %d %d\n", 10, 20);

  return 0;
}