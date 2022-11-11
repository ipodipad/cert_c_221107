
#include <stdio.h>

// 1. if, for, while 문의 문장이 하나만 존재하더라도,
//    반드시 중괄호를 사용해야 합니다.
#if 0
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
#endif

enum
{
  GUEST,
  ADMINISTRATOR,
  USER,
};

int is_user_login(void) { return 1; }
int is_guest(void) { return 1; }

// 2. if - else if 구조는 반드시 else를 사용해야 합니다.
int main(void)
{
#if 0
  /* NO */
  int level = ADMINISTRATOR;
  if (is_user_login())
  {
    level = USER;
  }
  else if (is_guest())
  {
    level = GUEST;
  }
#endif

  /* 해결 방법 */
  int level;
  if (is_user_login())
  {
    level = USER;
  }
  else if (is_guest())
  {
    level = GUEST;
  }
  else
  {
    level = ADMINISTRATOR;
  }

  int level = ADMINISTRATOR;
  if (is_user_login())
  {
    level = USER;
  }
  else if (is_guest())
  {
    level = GUEST;
  }
  else
  {
    /* Nothing - Optional */
    ;
  }

  /* OK */
  // 단순한 if 구조는 else로 끝날 필요가 없습니다.
  if (is_user_login())
  {
    level = USER;
  }

  return 0;
}