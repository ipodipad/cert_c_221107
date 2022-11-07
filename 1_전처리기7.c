// 1_전처리기7.c

// => 매크로 함수를 인라인 함수로 대체할 수 있다면, 인라인 함수가 선호되어야 한다.
//   - 매크로 함수를 인라인 함수로 대체할 수 없는 경우가 있습니다.

// 예외 1. 매크로 함수를 사용해서, 토큰을 연결하거나, 문자열 변경 기능을 사용할 때
#if 0
#include <stdio.h>

enum Color
{
  Color_Red,
  Color_Blue,
  Color_Green
};

#if 0
struct color
{
  enum Color color;
  const char *name;
} colors[] = {
    {Color_Red, "Red"},
    {Color_Green, "Green"},
    {Color_Blue, "Blue"},
};
#endif

#define COLOR(color)      \
  {                       \
    Color_##color, #color \
  }

struct color
{
  enum Color color;
  const char *name;
} colors[] = {
    COLOR(Red), // { Color_##Red, #Red } => { Color_Red, "Red" }
    COLOR(Green),
    COLOR(Blue),
};

int main(void)
{
  for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++)
  {
    printf("%d %s\n", colors[i].color, colors[i].name);
  }

  return 0;
}
#endif

#include <stdio.h>

// #, ##
#define TO_STR(str) #str
#define CONCAT(a, b) a##b

int main(void)
{
  int n1 = 10;
  int n2 = 20;
  int n3 = 30;

  printf("%d %d %d\n", CONCAT(n, 1), CONCAT(n, 2), CONCAT(n, 3));
  //                    n##1 => n1     n##2 => n2   n##3 => n3

  printf("%s\n", TO_STR(hello));
  //              #hello => "hello"

  return 0;
}