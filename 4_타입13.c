// 4_타입13.c

#include <stdio.h>

// 정확한 계산이 필요할 때, 소수점을 배제해서 사용할 수 있는지를 고려해야 합니다.

#if 0
float mean(float *arr, size_t len)
{
  float total = .0F; // 0.F, 0.0F, .0F

  for (size_t i = 0; i < len; i++)
  {
    total += arr[i];
    printf("arr[%zu] = %.10f total=%f\n", i, arr[i], total);
  }

  return (len == 0) ? 0 : total / len;
}

int main(void)
{
  float arr[10];
  for (size_t i = 0; i < 10; i++)
  {
    arr[i] = 10.1F;
  }

  float result = mean(arr, 10);
  printf("result: %f\n", result);

  return 0;
}
#endif

float mean(float *arr, size_t len)
{
  float total = .0F; // 0.F, 0.0F, .0F

  for (size_t i = 0; i < len; i++)
  {
    total += arr[i];
    printf("arr[%zu] = %.10f total=%f\n", i, arr[i], total);
  }

  return (len == 0) ? 0 : total / len;
}

int main(void)
{
  float arr[10];
  for (size_t i = 0; i < 10; i++)
  {
    arr[i] = 10.1F * 1000; /* 핵심 */
  }

  float result = mean(arr, 10);
  printf("result: %.20f\n", result / 1000);

  return 0;
}