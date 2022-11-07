// 1_전처리기2.c
#if 0
#include <stdio.h>

int dbl(int x) { return x + x; }
/* 잘못된 코드 */
// #define DBL(x) (x) + (x)

// 매크로로 치환되는 영역은 반드시 괄호로 감싸야 합니다.
// => 우선순위에 대한 문제가 발생할 수 있습니다.
#define DBL(x) ((x) + (x))

int main(void)
{
  int x = 10;

  int result1 = dbl(x + x) * dbl(2);
  printf("result1: %d\n", result1);

  int result2 = DBL(x + x) * DBL(2);
  //             (x+x) + (x+x) * (2) + (2)
  //             ((x+x) + (x+x)) * ((2) + (2))
  printf("result2: %d\n", result2);

  return 0;
}
#endif

#include <stdio.h>

// 매크로 상수를 사용할 때도 괄호로 감싸 주는 것이 좋습니다.
/* 잘못된 코드 */
#if 0
#define INFO -1
#define WARN -2
#define ERR -3
#endif

// 해결 방법: 매크로 치환 영역은 괄호로 감싸주어야 합니다.
#if 0
#define INFO (-1)
#define WARN (-2)
#define ERR (-3)
#endif

// 해결 방법: 열거 타입 상수를 이용하면 됩니다.
//  1) 텍스트 치환(전처리기)으로 인한 오류를 방지할 수 있습니다.
//  2) 전처리 이후에도 심볼 정보만 유지됩니다.
#if 1
enum
{
  INFO = -1,
  WARN = -2,
  ERR = -3
};
#endif
// 한계: 정수 타입에 대해서만 사용할 수 있습니다.

void log_print(int level, const char *message)
{
  // if (level INFO) /* Compile Error */

  if (level == INFO)
  {
    printf("[INFO] %s\n", message);
  }
  else if (level == WARN)
  {
    printf("[WARN] %s\n", message);
  }
  else
  {
    printf("[ERROR] %s\n", message);
  }
}

int main(void)
{
  log_print(ERR, "Service error!");
  return 0;
}