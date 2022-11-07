// 1_전처리기6.c

#if 0
#include <stdio.h>

int operations = 0;
int calls_to_f = 0;
int calls_to_g = 0;

#define F(x) (++operations, ++calls_to_f, 2 * (x))
#define G(x) (++operations, ++calls_to_g, (x) + 1)

int main(void)
{
  // printf("%d\n", (1, 2, 3));

  int result;
  int x = 10;

  /* 미정의 동작 */
  result = F(x) + G(x);
  //   result = (++operations, ++calls_to_f, 2 * (x)) + (++operations, ++calls_to_g, (x) + 1);

  printf("result: %d\n", result);
  printf("%d %d %d\n", operations, calls_to_f, calls_to_g);

  return 0;
}
#endif

#include <stdio.h>

int operations = 0;
int calls_to_f = 0;
int calls_to_g = 0;

#define F(x) (++operations, ++calls_to_f, 2 * (x))
#define G(x) (++operations, ++calls_to_g, (x) + 1)

static inline int f(int x)
{
  ++operations;
  ++calls_to_f;
  return 2 * x;
}

static inline int g(int x)
{
  ++operations;
  ++calls_to_g;
  return x + 1;
}

int main(void)
{
  int result;
  int x = 10;

  // result = f(x) + g(x); /* 미지정 동작 */
  int result_f = f(x);
  int result_g = g(x);

  result = result_f + result_g;

  printf("result: %d\n", result);
  printf("%d %d %d\n", operations, calls_to_f, calls_to_g);

  return 0;
}