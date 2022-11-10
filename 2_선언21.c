
// 2_선언21.c
#include <unistd.h>

#include <pthread.h>
#include <stdio.h>

// 프로세스의 내의 모든 스레드가 공유하는 자원인가?
//  1. 공유하는 자원 => 동기화
#if 0
int cnt = 0;

void *foo(void *arg)
{
  for (int i = 0; i < 1000000; ++i)
  {
    cnt++;
  }

  printf("foo: %d\n", cnt);

  return NULL;
}

int main(void)
{
  pthread_t thread;
  pthread_create(&thread, NULL, foo, NULL);

  for (int i = 0; i < 1000000; ++i)
  {
    cnt++;
  }

  pthread_join(thread, NULL);
  printf("main: %d\n", cnt);

  return 0;
}
#endif

#if 0
int cnt = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *foo(void *arg)
{
  for (int i = 0; i < 1000000; ++i)
  {
    pthread_mutex_lock(&lock);
    cnt++;
    pthread_mutex_unlock(&lock);
  }

  pthread_mutex_lock(&lock);
  printf("foo: %d\n", cnt);
  pthread_mutex_unlock(&lock);

  return NULL;
}

int main(void)
{
  pthread_t thread;
  pthread_create(&thread, NULL, foo, NULL);

  for (int i = 0; i < 1000000; ++i)
  {
    pthread_mutex_lock(&lock);
    cnt++;
    pthread_mutex_unlock(&lock);
  }
  pthread_join(thread, NULL);

  printf("main: %d\n", cnt);

  return 0;
}
#endif

#if 0
int cnt = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *foo(void *arg)
{
  int local = 0;
  for (int i = 0; i < 1000000; ++i)
  {
    local++;
  }

  pthread_mutex_lock(&lock);
  cnt += local;
  pthread_mutex_unlock(&lock);

  return NULL;
}

int main(void)
{
  pthread_t thread;
  pthread_create(&thread, NULL, foo, NULL);

  int local = 0;
  for (int i = 0; i < 1000000; ++i)
  {
    local++;
  }

  pthread_mutex_lock(&lock);
  cnt += local;
  pthread_mutex_unlock(&lock);

  pthread_join(thread, NULL);

  printf("main: %d\n", cnt);

  return 0;
}
#endif

// 2. 스레드마다 독립적인 정적 변수
//  => TLS(Thread Local Stroage) / TSD(Thread Specific Data)
//   1) 정적 TLS
//    => __thread int cnt = 0;
//   2) 동적 TLS
//    => 스레드 함수
//       pthread_setspecific
//       pthread_getspecific

__thread int cnt = 0;

void *foo(void *arg)
{
  printf("foo: %p\n", &cnt);
  for (int i = 0; i < 1000000; ++i)
  {
    cnt++;
  }

  printf("foo: %d\n", cnt);

  return NULL;
}

int main(void)
{
  pthread_t thread;
  pthread_create(&thread, NULL, foo, NULL);

  printf("main: %p\n", &cnt);
  for (int i = 0; i < 1000000; ++i)
  {
    cnt++;
  }

  pthread_join(thread, NULL);
  printf("main: %d\n", cnt);

  return 0;
}

// C11에 스레드 API가 표준으로 도입되었습니다.
// => 더이상 플랫폼 종속적인 API를 이용해서 스레드를 만들 필요가 없습니다.
// => 하지만, 필수가 아니라 옵션입니다.
//    많은 컴파일러가 해당 기능을 제공하지 않습니다.
// #include <threads.h> // C11

// #include <thread> // C++11