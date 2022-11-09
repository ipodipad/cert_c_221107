// test.h
#ifndef TEST_H
#define TEST_H

#if 0
struct user
{
private:
  int age = 10; /* C++ 문법 */
};
#endif

class user
{
  int age = 10; /* C++ 문법 */
};

// C++ pImpl idiom
//  => 컴파일러 방화벽

#endif