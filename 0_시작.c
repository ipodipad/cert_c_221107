// 0_시작.c
#include <stdio.h>

// * Visual Studio
// 1.       Compile: Ctrl + F7
// 2. Compile + Run: Ctrl + F5

// 1. C11 표준을 기준으로 진행됩니다.
//    C89, C90
//    C99 - *, MISRA2012
//    C11 - CERT C
//    C17

// 2. 시큐어 코딩
//   > 안전한 소프트웨어 개발을 위해서, 소스코드에 존재할 수 있는
//     잠재적인 보안 취약점을 제거하고, 보안을 고려하여 기능을 설계하고
//     구현하는 행위

// 3. 필요성
//   - 릴리즈 이전에 SW 취약점을 50% 줄이면, 침해사고 대응 비용 75% 감소
//     => Gartner
//   - 보안 취약점의 92%는 네트워크가 아닌 애플리케이션에서 발생 => NIST
//   - 릴리즈 이후에 오류 수정 $30,000 비용 소요, 개발중 오류 수정 약 $5,000면
//     충분 => NIST
//   - 릴리즈 이후 오류를 수정할 경우, 설계 단계보다 비용이 100% 증가 => IBM

// 4. 가이드라인
//   - OWASP: Open Web Application Security Project
//   -  CERT: Computer Emergency Response Team => C11
//   -   CWE: Common Weakness Enumeration
//   - MISRA: Motor Industry Software Reliablilty Association
//          => MISRA:2012, C99

// 5. C 언어 장점
//   - C 컴파일러는 많은 프로세서에서 쉽게 사용할 수 있습니다.
//     "이식성"
//   - C 프로그램은 효율적인 기계 코드로 컴파일 될 수 있습니다.
//   - 국제 표준 기구(ISO)에 의해 정의됩니다.

int main(void)
{
  printf("Hello, C\n");
  return 0;
}
