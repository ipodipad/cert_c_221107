// 2_선언3.c
#include <stdio.h>

#if 0
int get_fd(void) { return -1; }

char msg[32];

void set_error(const char *message)
{
  sprintf(msg, "Error: %s\n", message);
  // sprintf은 배열의 길이가 초과되는 버퍼 오버플로우가 발생할 수 있으므로
  // 사용하지 말아야 합니다.
}

int main(void)
{
  int fd = get_fd();
  if (fd == -1)
  {
    set_error("get_fd error");
    // return 1;
  }

  printf("error message: %s\n", msg);
  return 0;
}
#endif

#if 0
int get_fd(void) { return -1; }

// 전역 변수는 함수 안에서 가려질 수 있는 문제가 발생할 수 있으므로,
// 이름을 좀더 설명적으로 작성해야 합니다.
char msg[32];
const size_t msgsize = sizeof(msg);

void set_error(const char *message)
{
  char msg[16]; /* 의도하지 않은 충돌나는 지역 변수 */

  snprintf(msg, msgsize, "Error: %s\n", message);
  // sprintf(msg, "Error: %s\n", message);
}

int main(void)
{
  int fd = get_fd();
  if (fd == -1)
  {
    set_error("get_fd error 오류가 발생하였습니다.");
    // return 1;
  }

  printf("error message: %s\n", msg);
  return 0;
}
#endif

int get_fd(void) { return -1; }

// 전역 변수는 함수 안에서 가려질 수 있는 문제가 발생할 수 있으므로,
// 이름을 좀더 설명적으로 작성해야 합니다.
char system_message[128];
const size_t system_message_size = sizeof(system_message);

void set_error(const char *message)
{
  char msg[16];

  snprintf(system_message, system_message_size, "Error: %s\n", message);
}

int main(void)
{
  int fd = get_fd();
  if (fd == -1)
  {
    set_error("get_fd error 오류가 발생하였습니다.");
    // return 1;
  }

  printf("error message: %s\n", system_message);
  return 0;
}