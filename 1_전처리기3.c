// 1_전처리기3.c
#include <stdio.h>

// 1. 매크로 함수를 사용할 때, 반드시 매개 변수에 괄호를 사용해야 합니다.
//   #define SQR(x) (x) * (x)

// 2. 매크로 함수를 사용할 때, 치환 영역을 괄호로 감싸주어야 합니다.
//   #define SQR(x) ((x) * (x))
//   #define INFO (-1)

int getpid(void) { return 42; }

// 예외 1.
//   단일 식별자 또는 함수 호출로 확장되는 매크로는
//   주변 식에 의한 연산자 우선순위의 영향을 받지 않기 때문에
//   치환 목록을 괄호로 묶어줄 필요가 없습니다.
#define MY_PID getpid()
#define GET_PID getpid

// 예외 2.
//   배열 참조 연산자를 사용해여 배열 참조로 확장되는 매크로 또는
//   구조체(공용체) 멤버 접근 연산자를 사용하여 객체의 멤버를 지정하는 표현식
//   ., ->
//   => 우선순위에 영향을 받지 않으므로 치환 목록을 괄호로 묶어줄 필요가 없습니다.

#define MAX_NAME_SIZE 10
#define FIRST_INDEX 0

#define NEXT_FREE block->next_free
#define CID record.account.cid
#define ARR array[MAX_NAME_SIZE]

int main(void)
{
  int arr[MAX_NAME_SIZE];
  arr[FIRST_INDEX] = 10;

  printf("%d\n", MY_PID);
  printf("%d\n", GET_PID());

  return 0;
}