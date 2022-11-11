// 4_타입7.c

#include <stdio.h>
#include <stdlib.h>

// 1. 신뢰할 수 없는 소스로부터의 입력은 반드시 검사해야 합니다.
// 2. 상한값과 하한값에 대한 검사가 필요합니다.

// int main(int argc, char **argv)
#if 0
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "./a.out [table_size]");
    exit(1);
  }

  int table_size = atoi(argv[1]);

  int *table = malloc(sizeof(int) * table_size);
  table[0] = 42; /* 미정의 동작 가능성 */

  for (int i = 0; i < table_size; ++i)
  {
    printf("%3d", table[i]);
  }
  printf("\n");

  free(table);

  return 0;
}
#endif

enum
{
  MIN_TABLE_SIZE = 5,
  MAX_TABLE_SIZE = 32
};

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "./a.out [table_size]");
    exit(1);
  }

  int table_size = atoi(argv[1]);
  if (table_size > MAX_TABLE_SIZE || table_size < MIN_TABLE_SIZE)
  {
    fprintf(stderr, "./a.out [5-32]");
    exit(1);
  }

  int *table = malloc(sizeof(int) * table_size);
  table[0] = 42; /* 미정의 동작 가능성 */

  for (int i = 0; i < table_size; ++i)
  {
    printf("%3d", table[i]);
  }
  printf("\n");

  free(table);

  return 0;
}
