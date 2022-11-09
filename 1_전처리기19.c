// 1_전처리기19.c

#if 0
#include <stdio.h>

// 가변인자 매크로
// : 매크로 함수에서 인자를 다양하게 전달받을 수 있는 가변인자를 지원합니다.
// => c99 표준입니다.
#define TRACE(fmt, ...) \
  fprintf(stderr, "%s:%d (%s): " fmt, __FILE__, __LINE__, __func__, __VA_ARGS__)

int main(void)
{
  TRACE("Hello world - %d %d %s\n", 10, 20, "world");
  // TRACE("123123"); /* Compile Error */
  return 0;
}
#endif

#if 1
#include <stdio.h>

void show(int n)
{
  printf("show: %d\n", n);
}

#define FE_1(FUNC, X) FUNC(X)

#define FE_2(FUNC, X, ...)   \
  do                         \
  {                          \
    FUNC(X);                 \
    FE_1(FUNC, __VA_ARGS__); \
  } while (0)

#define FE_3(FUNC, X, ...)   \
  do                         \
  {                          \
    FUNC(X);                 \
    FE_2(FUNC, __VA_ARGS__); \
  } while (0)

#define FE_4(FUNC, X, ...)   \
  do                         \
  {                          \
    FUNC(X);                 \
    FE_3(FUNC, __VA_ARGS__); \
  } while (0)

#define FE_5(FUNC, X, ...)   \
  do                         \
  {                          \
    FUNC(X);                 \
    FE_4(FUNC, __VA_ARGS__); \
  } while (0)

#if 0
int main(void)
{
  FE_1(show, 10); // show(10)

  FE_2(show, 10, 20);
  // show(10); FE_1(show, 20); => show(10); show(20);

  FE_3(show, 10, 20, 30);
  // show(10); FE_2(show, 20, 30)
  // => show(10); show(20); FE_1(show, 30)
  // => show(10); show(20); show(30);

  FE_5(show, 10, 20, 30, 40, 50);

  return 0;
}
#endif

// 인자 개수를 직접 첫번째 인자로 전달해야 합니다.

#if 0
#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)

#define FOREACH_N(N, FUNC, ...) CONCAT(FE_, N)(FUNC, __VA_ARGS__)

int main(void)
{
  FOREACH_N(3, show, 10, 20, 30);         // => FE_3(show, 10, 20, 30)
  FOREACH_N(5, show, 10, 20, 30, 40, 50); // => FE_5(show, 10, 20, 30, 40, 50)

  return 0;
}
#endif

#if 0
#define COUNT_IMPL(_1, _2, _3, _4, _5, N, ...) N
#define COUNT(...) COUNT_IMPL(__VA_ARGS__, 5, 4, 3, 2, 1, 0)

int main(void)
{
  int n = COUNT(1, 2, 3);
  //    COUNT_IMPL(1,  2,  3,  5,  4,  3, 2, 1, 0)
  //              _1, _2, _3, _4, _5, [N]
  printf("%d\n", n);

  n = COUNT(1, 2, 3, 4, 5);
  //  COUNT_IMPL(1,  2,  3,  4,  5,  5,  4, 3, 2, 1, 0)
  //            _1, _2, _3, _4, _5, [N]
  printf("%d\n", n);

  n = COUNT();
  //  COUNT_IMPL(5,  4,  3,  2,  1,  0)
  //            _1, _2, _3, _4, _5, [N]

  return 0;
}
#endif

#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)
#define FOREACH_N(N, FUNC, ...) CONCAT(FE_, N)(FUNC, __VA_ARGS__)

#define COUNT_IMPL(_1, _2, _3, _4, _5, N, ...) N
#define COUNT(...) COUNT_IMPL(__VA_ARGS__, 5, 4, 3, 2, 1, 0)

#define FOREACH(FUNC, ...) FOREACH_N(COUNT(__VA_ARGS__), FUNC, __VA_ARGS__)

#if 0
int main(void)
{
  FOREACH(show, 10, 20, 30);

  FOREACH(show, 10, 20, 30, 40, 50);

  FOREACH(show, 10, 20);

  return 0;
}
#endif

#endif