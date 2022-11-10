// 3_표현식15.c
#include <stdio.h>

// goto 사용하면 안됩니다.
// > goto를 제한없이 사용하면, 이해하기 어려운 프로그램이 됩니다.
//   goto를 허용되는 예외를 제외하고, goto문을 사용하면 안됩니다.
#if 0
int main(void)
{
  int a = 10;

restart:
  if (a > 0)
  {
    goto fail; /* OK */
  }

  if (a % 2 == 0)
  {
    // goto 문은 반드시 goto 이후에 선언된 같은 함수 내의 라벨에 대해서만
    // 점프를 수행해야 합니다.
    goto restart; /* NO, 허용되지 않습니다. */
  }

fail:

  return 0;
}
#endif

// 중첩된 루프를 flag를 통해 탈출합니다.
#if 0
int main(void)
{
  int flag = 0;

  for (int i = 0; i < 10; ++i)
  {
    for (int j = 0; j < 10; ++j)
    {
      if (j == 2)
      {
        flag = 1;
        break;
      }
    }

    if (flag)
    {
      break;
    }
  }
}
#endif

#if 0
// goto
// 1) 중첩된 루프의 탈출에서 매우 유용합니다.
int main(void)
{
  for (int i = 0; i < 10; ++i)
  {
    for (int j = 0; j < 10; ++j)
    {
      if (i == 2)
      {
        goto out; // 중첩된 루프를 한번에 탈출 가능합니다.
      }

      printf("%d\n", j);
    }
  }

out:

  return 0;
}
#endif

typedef int error_t;

enum
{
  FILE_OPEN_ERROR,
};

error_t
copy_file(const char *src, const char *dest1, const char *dest2)
{
  FILE *sfp = fopen(src, "r");
  if (NULL == sfp)
  {
    return FILE_OPEN_ERROR;
  }

  FILE *dfp1 = fopen(dest1, "w");
  if (NULL == dfp1)
  {
    fclose(sfp);
    return FILE_OPEN_ERROR;
  }

  FILE *dfp2 = fopen(dest2, "w");
  if (NULL == dfp2)
  {
    fclose(dfp1);
    fclose(sfp);
    return FILE_OPEN_ERROR;
  }

  char ch;
  while ((ch = fgetc(sfp)) != EOF)
  {
    fputc(ch, dfp1);
    fputc(ch, dfp2);
  }

  fclose(dfp2);
  fclose(dfp1);
  fclose(sfp);

  return 0;
}

int main(void)
{
  error_t error = copy_file("0_시작.c", "result1.c", "result2.c");
  if (error == 0)
  {
    printf("OK!\n");
  }

  return 0;
}
