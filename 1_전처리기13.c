// 1_전처리기13.c

#include <stdio.h>

// 미리 정의된 매크로
// 1. __FILE__: 현재 소스 파일명
// 2. __LINE__: 현재 라인 번호
// 3. __DATE__: 현재 소스를 컴파일한 날짜
// 4. __TIME__: 현재 소스를 컴파일한 시간

// 5. __func__: 현재 함수의 이름, c99
//              매크로가 아니라 컴파일러에 의해 자동으로 정의되는
//              문자열 상수(const char*) 입니다.
// 6.         __STDC__: 컴파일러가 표준을 지원하면 1, c99
// 7. __STDC_VERSION__: 컴파일러가 사용하는 현재 표준 버전, c99
//    c99: 199901
//    c11: 201112
//    c17: 201710

int main(void)
{
  printf("%s %d %s %s\n", __FILE__, __LINE__, __DATE__, __TIME__);
  printf("%s\n", __func__);

#ifdef __STDC__
  printf("%d\n", __STDC__);
#endif

#if defined(__STDC_VERSION__)
  printf("%ld\n", __STDC_VERSION__);
#endif

  return 0;
}