#include "sample.h"

#if 0
int add(int a, int b)
{
  return a + b;
}
#endif
// 인라인 함수는 구현이 헤더 파일을 통해서 제공되어야 합니다.

// external linkage
// => 파일에 두어야 합니다.
//    헤더가 둘 경우 심볼 충돌이 발생합니다.

// internal linkage
// => 헤더: 어디에서든 사용이 가능하다.
//   예) 상수, 인라인 함수
// => 소스: 소스 파일 내부에서만 접근이 하도록 하겠다.
