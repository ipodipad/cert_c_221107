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

#if 0
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
#endif

// 문제점
// => 최적화가 적용된 바이너리에서 문제가 발생할 수 있습니다.

// 메모리 가시성 문제
//  > CPU는 성능상의 이유로 변수를 읽을 때, 메모리로부터 직접 읽어 오는 것이 아니라 CPU의 캐시를 사용해서 읽어옵니다.
//  > 다른 컨텍스트에서 변경된 데이터 또는 하드웨어에 의해서 변경되는 데이터(메모리에 대한 변경사항)
//    캐시에 반영되지 않아서 발생하는 문제입니다.

// 해결 방법
//  > 변수의 값을 캐시로부터 읽어오는 것이 아니라,
//    반드시 메모리로부터 반영되어야 한다는 사실을 컴파일러에게 알려주어야 합니다.
//    : volatile
//      volatile 한정자는 프로그램이 아닌 외부적인 요소에 의해 값의 변경이 될 수 있음을
//      컴파일러에게 알려주는 키워드입니다.
//      컴파일러는 volatile로 지정된 변수에 대해서 캐싱을 제한합니다.

int flag = 1;

void handler(int signum)
{
  printf("handler\n");
  flag = 0;
}

//       flag=1         flag=0
// [CPU] [Cache] ------> [Mem]
//                         ^
//                         |
//                       SIGINT

void process(void)
{
  while (flag)
  {
    //...
  }
  printf("process end\n");
}

int main(void)
{
  signal(SIGINT, handler);

  process();
  printf("main end\n");

  return 0;
}