// 2_선언14.c
#include <stdio.h>

#if 0
struct obj
{
  int i;
  float f;
};
typedef struct obj OBJECT;
typedef struct obj *POBJECT;
#endif

#if 0
typedef struct obj
{
  int i;
  float f;
} OBJECT, *POBJECT;

// const POBJECT obj
//  => struct obj* const p;
//   : 대상체에 대한 const가 아니라 자기 자신에 대한 const로 적용됩니다.

// 문제점: "포인터를 typedef 한 경우, const가 의도한대로 동작하지 않을 수 있습니다."
void print_obj(const POBJECT obj)
{
  printf("%d %f\n", obj->i, obj->f);

  // obj->f = 5.8F; /* 의도하지 않은 변경 */
}

int main(void)
{
  // int a, *b;
  // a: int
  // b: int*

  // struct obj o;
  OBJECT o = {42, 3.14F};
  POBJECT p = &o;

  print_obj(&o);
  print_obj(p);

  // printf("%d %f\n", o.i, o.f);
  // printf("%d %f\n", p->i, p->f);

  return 0;
}
#endif

#if 0
// 해결 방법 1.
//  => 포인터에 대한 typedef는 사용하지 않는 것이 좋습니다.
//     포인터가 아닌 타입에 대해서만 typedef를 수행하자.
typedef struct obj
{
  int i;
  float f;
} OBJECT;

void print_obj(const OBJECT *obj)
{
  printf("%d %f\n", obj->i, obj->f);

  // obj->f = 5.8F; /* 컴파일 오류 */
}

int main(void)
{
  OBJECT o = {42, 3.14F};
  OBJECT *p = &o;

  print_obj(&o);
  print_obj(p);

  return 0;
}
#endif

// 해결 방법 2. Windows가 사용하는 전통적인 방식
//  => 읽기 전용 포인터에 대한 typedef를 별도로 제공합니다.

typedef struct obj
{
  int i;
  float f;
} OBJECT;

typedef OBJECT *POBJECT;
typedef const OBJECT *PCOBJECT;

void print_obj(PCOBJECT obj)
{
  printf("%d %f\n", obj->i, obj->f);

  // obj->f = 5.8F; /* 컴파일 오류 */
}

int main(void)
{
  OBJECT o = {42, 3.14F};
  OBJECT *p = &o;

  print_obj(&o);
  print_obj(p);

  return 0;
}