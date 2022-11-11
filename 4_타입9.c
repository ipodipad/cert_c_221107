
#include <stdio.h>
#include <stdlib.h>

// 1. index가 음수일 경우, -index의 결과가 나오고, 유효하지 않은 메모리를
//    참조하는 미정의 동작이 발생합니다.

// 2. index+1의 결과가 오버플로우 발생하면, 미정의 동작이 발생합니다.

// 3. 정수 나누기 / 나머지 연산
//   1) C99 이전에는 음수 피연산자에 대한 나누기, 나머지 연산이 미지정 동작이었습니다.
//   2) C99 에서는 다음과 같이 표준이 변경되었습니다.
//     - 나눗셈 연산의 결과는 첫번째 피연산자를 두번째 피연산자로 나눈 몫입니다.
//     - 나머지 연산의 결과는 나머지입니다.
//     - 두 연산에서 두번째 연산이 0인 경우, 미정의 동작이 발생합니다.
//     - 정수가 나누어질 때, 나누기 연산의 결과는 수학적인 몫으로 소수점 이하의 값은 버려집니다.
//     - 결과의 부호는 첫번째 피 연산자의 부호를 따릅니다.
//     => (a/b) * b + (a%b) => a와 동일합니다.

#if 0
int insert(int index, int *list, int size, int value)
{
  if (size != 0)
  {
    //  : index == -2
    // index = (index + 1) % size; // 1

    //  : index == INT_MAX
    // index = abs((index + 1) % size); // 2

    list[index] = value;
    return index;
  }
  else
  {
    return -1;
  }
}

int main(void)
{
  return 0;
}
#endif

// 해결 방법
// 1) 경계 체크를 해야 합니다.
// 2) 타입을 정확하게 설계해야 합니다.
//  => 길이와 크기는 음수가 될 수 없으므로, unsigned 기반의 타입을 이용해야 합니다.
//     : size_t

// int insert(int index, int *list, int size, int value)

int insert(size_t index, int *list, size_t size, int value)
{
  // if (size != 0 && (index >= 0 && index < size))
  if (size != 0 && index < size)
  {
    index = (index + 1) % size;

    list[index] = value;
    return index;
  }
  else
  {
    return -1;
  }
}

int main(void)
{
  return 0;
}