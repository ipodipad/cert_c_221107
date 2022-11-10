#ifndef SAMPLE_H
#define SAMPLE_H

// extern int add(int a, int b);

// 인라인 함수는 구현이 헤더 파일을 통해서 제공되어야 합니다.
static inline int add(int a, int b)
{
  return a + b;
}

// C - extern
// C++ - static
static const int MAX_SIZE = 128;

#endif