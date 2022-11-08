// 1_전처리기14.c

#include <stdio.h>

// 1. 여러개의 문자열을 하나의 문자열로 합쳐줍니다.
//   "aaa""bbb" => "aaabbb"

// 2. __LINE__은 매크로 함수에서 사용해야 합니다.

// #define TO_STR(x) #x
// => 1단계로 사용할 경우, 매크로에 대한 치환이 발생하지 않고, 문자열화 됩니다.

// 해결 방법
#define TO_STR_IMPL(x) #x
#define TO_STR(x) TO_STR_IMPL(x)

#define LOG(msg) fprintf(stderr, "["__FILE__ \
                                 "(" TO_STR(__LINE__) ")] " msg "\n")

#define PI 3.14

int main(void)
{
  // [1_전처리기14.c(__LINE__)] hello, world
  LOG("hello, world");

  printf("%s\n", TO_STR(3.14));
  //   TO_STR(3.14) -> #3.14  -> "3.14"

  printf("%s\n", TO_STR(PI));
  //   TO_STR(PI)  -> #PI  -> "PI"
  //   TO_STR(PI)  -> TO_STR_IMPL(3.14) -> #3.14 -> "3.14"

  return 0;
}