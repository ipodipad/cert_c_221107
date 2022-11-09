// 2_선언19.c
#include <signal.h>
// 시그널: IPC(프로세스간 통신)
//       프로세스에게 다양한 시그널을 전달할 수 있습니다.
//       "시그널의 기본 동작은 프로세스의 종료입니다."

// 키보드: ^C - SIGINT
//       ^\ - SIGQUIT

#include <stdio.h>

// void (*signal(int, void (*)(int)))(int)
//  > 프로세스가 시그널을 받았을 때의 동작을 정의할 수 있습니다.

// typedef void (*sighandler_t)(int)
// sighandler_t signal(int, sighandler_t)

//   1. signal(int, void (*)(int))
//    > signal은 int와 int를 인자로 받고, 반환값이 없는 함수 포인터를 인자로 받는 함수입니다.
//      함수의 반환타입은?

//   2. (*signal(int, void (*)(int)))
//   > 함수의 포인터 타입입니다. 포인터가 가르키는 것은?

//   3. (*signal(int, void (*)(int)))(int)
//   > 포인터가 가르키는 것은 int를 인자로 받는 함수입니다.
//     함수의 반환타입은?

//   4. void (*signal(int, void (*)(int)))(int)
//   > 함수의 반환타입은 없습니다.

void handler(int signum)
{
  printf("handler\n");
}

int main(void)
{
  signal(SIGINT, handler);

  getchar();

  return 0;
}