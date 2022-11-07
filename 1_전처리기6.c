// 1_전처리기6.c

#include <stdio.h>

int operations = 0;
int calls_to_f = 0;
int calls_to_g = 0;

#define F(x) (++operations, ++calls_to_f, 2 * (x))
#define G(x) (++operations, ++calls_to_g, (x) + 1)

int main(void)
{
  int result;
  int x = 10;

  result = F(x) + G(x);
  printf("result: %d\n", result);
  printf("%d %d %d\n", operations, calls_to_f, calls_to_g);

  return 0;
}