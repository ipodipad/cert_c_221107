// 4_타입8.c

#include <stdio.h>

// scanf 계열 함수
//  => 유효하지 않은 값의 입력에 대해서 신뢰성 있는 처리를 할 수 없습니다.
#if 0
int main(void)
{
  int buf;
  printf("Input number: ");

  int ret = scanf("%d", &buf);
  if (ret != 1)
  {
    printf("Input error\n");
  }
  else
  {
    printf("-----> %d\n", buf);
  }

  return 0;
}
#endif

#include <errno.h>

// 해결 방법 1. Linux scanf는 기본 제공하는 추가적인 오류 처리 방법이 있습니다.
//  => 입력 받은 데이터의 길이가 초과된 경우, ERANGE 오류 코드로 처리할 수
//     있습니다.
//  "플랫폼 의존성이 발생할 수 있습니다"
#if 0
int main(void)
{
  int data;
  if (scanf("%d", &data) != 1)
  {
    printf("error\n");
  }
  else if (ERANGE == errno)
  {
    printf("Out of range\n");
  }
  else
  {
    printf("%d\n", data);
  }

  return 0;
}
#endif

#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>

// 해결 방법 2.
//  => 입력 데이터는 문자열로 입력 받습니다.

// 문자열을 정수로 변환할 때
//  atoi/atol/atoll 함수를 사용하면 안됩니다.
//   - 잘못된 값이 전달된 경우, 0을 반환합니다.
//    > 사용자가 정상적인 값을 입력해서 0인지, 오류라서 0인지가 구분할 수 없습니다.
//   - 잘못된 입력에 대한 오류처리 기능을 제공하지 않습니다.
//     전달된 값이 표현할 수 없는 값인 경우 미정의 동작이 발생합니다.

//  strtol 계열의 함수를 사용해야 합니다.
//   - strtol
//   - strtoll - C99
//   - strtoul
//   - strtoull - C99

int main(void)
{
  long data = 0;
  char buf[64];
  fgets(buf, sizeof(buf), stdin);

  /* 잘못된 코드 */
  // data = atoi(buf);

  char *end_ptr;

  data = strtol(buf, &end_ptr, 10);
  if (errno == ERANGE)
  {
    perror("strtol1");
  }
  else if (errno == EINVAL)
  {
    perror("strtol2");
  }
  else if (*end_ptr != '\n' && *end_ptr != '\0')
  {
    fprintf(stderr, "Extra chars in input data\n");
  }
  else
  {
    printf("%ld\n", data);
  }

  return 0;
}
