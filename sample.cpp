// sample.cpp
#include <deque>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

// past the end
// => C++에서 선형 자료구조(컨테이너)의
//    구간을 표현합니다.

// => [begin, end)
//    반개구간

int main(void)
{
  int v[5] = {1, 2, 3, 4, 5};

  auto p1 = begin(v); // 시작 위치
  auto p2 = end(v);   // 끝 다음 위치

  printf("%p %p\n", p2, v + 5);

  while (p1 != p2)
  {
    cout << *p1 << endl;
    ++p1;
  }

  return 0;
}

#if 0
int main(void)
{
  vector<int> v = {1, 2, 3, 4, 5};

  vector<int>::iterator p1 = v.begin();
  vector<int>::iterator p2 = v.end();

  while (p1 != p2)
  {
    cout << *p1 << endl;
    ++p1;
  }

  return 0;
}
#endif