
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
//  => TLS(Thread Local Stroage)
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