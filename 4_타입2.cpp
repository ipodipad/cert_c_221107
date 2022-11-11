#include <cstdint>
#include <iostream>
#include <string_view>
using namespace std;

template <typename T>
constexpr auto type_name()
{
  std::string_view name, prefix, suffix;
#ifdef __clang__
  name = __PRETTY_FUNCTION__;
  prefix = "auto type_name() [T = ";
  suffix = "]";
#elif defined(__GNUC__)
  name = __PRETTY_FUNCTION__;
  prefix = "constexpr auto type_name() [with T = ";
  suffix = "]";
#elif defined(_MSC_VER)
  name = __FUNCSIG__;
  prefix = "auto __cdecl type_name<";
  suffix = ">(void)";
#endif
  name.remove_prefix(prefix.size());
  name.remove_suffix(suffix.size());
  return name;
}

#define PRINT_TYPE(x) cout << type_name<decltype(x)>() << endl

#if 0
// 프로모션
int main(void)
{
  signed char c1 = 100;
  signed char c2 = 100;
  PRINT_TYPE(c1 + c2);

  short s1 = SHRT_MAX;
  short s2 = 1;
  PRINT_TYPE(s1 + s2);

  unsigned short s3 = SHRT_MAX;
  unsigned short s4 = SHRT_MAX;
  PRINT_TYPE(s3 + s4);

  signed char c3 = 100;
  signed char c4 = 100;
  signed char c5 = 4;
  PRINT_TYPE(c3 * c4 / c5);

  u_int16_t x = 45000;
  u_int16_t y = 50000;
  PRINT_TYPE(x * y);
  PRINT_TYPE((long)x * y);

  return 0;
}
#endif

int main(void)
{
  int a = 100;
  int b = INT_MAX;
  PRINT_TYPE(a + b);

  long c = 100;
  long d = LONG_MAX;
  PRINT_TYPE(c + d);

  int a2 = INT_MAX;
  long long b2 = INT_MAX;
  PRINT_TYPE(a2 + b2);

  int a3 = INT_MAX;
  unsigned int b3 = 10;
  PRINT_TYPE(a3 + b3);

  int a4 = INT_MAX;
  unsigned short b4 = 10;
  PRINT_TYPE(a4 + b4);

  long long a5 = 10;
  unsigned int b5 = INT_MAX;
  PRINT_TYPE(a5 + b5);

  long long a6 = 20;
  unsigned long b6 = LONG_MAX;
  PRINT_TYPE(a6 + b6);
}