
#include <stdio.h>

enum
{
  GUEST,
  ADMINISTRATOR,
};

int is_user_login(void) { return 1; }
int is_guest(void) { return 1; }

int main(void)
{
  int level;
  /*
  if (is_user_login())
    if (is_guest())
      level = GUEST;
  else
    level = ADMINISTRATOR;
  */
  /* 해결 방법 */

  // if, for, while 문의 문장이 하나만 존재하더라도,
  // 반드시 중괄호를 사용해야 합니다.
  if (is_user_login())
  {
    if (is_guest())
    {
      level = GUEST;
    }
  }
  else
  {
    level = ADMINISTRATOR;
  }

  return 0;
}