// 1_전처리기7.c

// 매크로 함수를 인라인 함수로 대체할 수 있다면, 인라인 함수가 선호되어야 한다.

#include <stdio.h>

// 예외 1. 매크로 함수를 사용해서, 토큰을 연결하거나, 문자열 변경 기능을 사용할 때

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
    COLOR(Red),
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