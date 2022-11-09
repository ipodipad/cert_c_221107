// #ifndef COMPLEX_H
// #define COMPLEX_H

#if !defined(COMPLEX_H)
#define COMPLEX_H

// #pragma once
// 표준이 아닙니다.
// : 일부 컴파일러는 지원하지만, 표준이 아니기 때문에 제대로 동작하지 않을 수 있습니다.

struct complex
{
  double real;
  double image;
};
// ODR(One Definition Rule)
// : C에서 구조체 등의 정의는 컴파일 단위에서 한번만 정의되어야 합니다.

#endif
