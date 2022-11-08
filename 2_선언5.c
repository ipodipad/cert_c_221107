// 2_선언5.c

#include <assert.h>
#include <stdio.h>

// #pragma pack(1) // 컴파일러 확장 명령

// 1. assert(단언문)은 취약성이 있는 소프트웨어의 결함을 찾아서 제거하는데 사용되는
//    효과적인 진단 도구 입니다.
// 2. assert 제약 사항
//   1) 프로그램 실행 중에 동작하기 때문에, 실행 시간 오버헤드가 존재합니다.
//   2) assert의 마지막 동작은 abort() 함수를 호출하기 때문에
//      서버 프로그램이나 임베디드 시스템에서 사용하기는 어렵습니다.

// 3. 상수 표현식에 대한 어썰션은 static assert(정적 어썰션)를 이용하는 것이 좋습니다.
// => 컴파일 타임에 조건이 성립되는지 여부를 확인할 수 있습니다.
//   1) 컴파일 타임에 동작하기 때문에, 실행 시간 오버헤드가 존재하지 않습니다.
//   2) c11에 표준으로 도입되었습니다.
//      _Static_assert / static_assert

struct packet
{
  char cmd;
  int len;
};

// 컴파일 타임에 조건을 체크하고, 조건이 만족되지 않는 경우,
// 컴파일 오류를 발생시킬 수 있습니다.
// char x[-1]; => 배열의 개수가 음수가 될 수 없는 특성을 이용합니다.

#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)

// c99
#define STATIC_ASSERT(expr) \
  typedef char CONCAT(assertion_failed_at_line_, __LINE__)[(expr) ? 1 : -1]

int main(void)
{
  printf("%lu\n", sizeof(struct packet));
  // assert(sizeof(struct packet) == 5);
  // STATIC_ASSERT(sizeof(struct packet) == 5);

  _Static_assert(sizeof(struct packet) == 5, "Packet size must 5");
  static_assert(sizeof(struct packet) == 5, "Packet size must 5");

  printf("Program Start\n");

  return 0;
}