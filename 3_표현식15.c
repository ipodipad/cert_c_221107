// 3_표현식15.c
#include <stdio.h>

// goto 사용하면 안됩니다.
// > goto를 제한없이 사용하면, 이해하기 어려운 프로그램이 됩니다.
//   goto를 허용되는 예외상황을 제외하고, goto문을 사용하면 안됩니다.
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

#if 0
int main(void)
{
  int flag1 = 0;
  int flag2 = 0;

  // 하나의 반복문 안에 1개 이상의 break 또는 goto문을 사용하면 안됩니다.
  for (int i = 0; i < 10; i++)
  {
    if (flag1 == 1)
    {
      break;
    }

    //...

    if (flag2 == 1)
    {
      break;
    }
  }
}
#endif

#if 1
typedef int error_t;

enum
{
  FILE_OPEN_ERROR,
};

// MISRA:2012
//  > 함수는 단일 종료 지점으로 만들어져야 합니다.
// => 함수의 결과를 생성하는 여러개의 종료 지점이 있는 경우,
//    함수를 실행할 때의 결과를 예측하기 어렵습니다.

#if 0
error_t copy_file(const char *src, const char *dest1, const char *dest2)
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
#endif

// goto
//  2) 오류 처리 루틴에서의 코드 중복을 제거할 수 있습니다.
//  3) 단일 종료 지점으로의 설계가 가능합니다.

error_t copy_file(const char *src, const char *dest1, const char *dest2)
{
  error_t error = 0;

  FILE *sfp = fopen(src, "r");
  if (NULL == sfp)
  {
    error = FILE_OPEN_ERROR;
    goto err_sfp;
  }

  FILE *dfp1 = fopen(dest1, "w");
  if (NULL == dfp1)
  {
    error = FILE_OPEN_ERROR;
    goto err_dfp1;
  }

  FILE *dfp2 = fopen(dest2, "w");
  if (NULL == dfp2)
  {
    error = FILE_OPEN_ERROR;
    goto err_dfp2;
  }

  /* 잘못된 코드 */
  //  : 0xff를 읽었을 때, char 타입으로 EOF와 구분할 수 없는
  //    문제가 발생합니다.

  // char ch;
  // EOF: End Of File => -1

  // EOF: 0xffffffff

  int ch;
  // char ch: 0xff       --> int --> 0xffffffff
  //  int ch: 0x000000ff

  while ((ch = fgetc(sfp)) != EOF)
  {
    fputc(ch, dfp1);
    fputc(ch, dfp2);
  }

  // 가장 최근에 생성된 자원부터 해지해야 합니다.
  fclose(dfp2);
err_dfp2:
  fclose(dfp1);
err_dfp1:
  fclose(sfp);
err_sfp:

  return error;
}

int main(void)
{
  // error_t error = copy_file("0_시작.c", "result1.c", "result2.c");
  error_t error = copy_file("a.out", "a.out2", "a.out3");

  if (error == 0)
  {
    printf("OK!\n");
  }

  return 0;
}
#endif