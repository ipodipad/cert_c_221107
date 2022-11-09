// 2_선언9.c
#include <stdio.h>

// b.h
// 선언
extern int global;
extern const int constant;

int data[10000] = {1, 2, 3};

int main(void)
{
  printf("global: %d\n", global);
  printf("constant: %d\n", constant);

  return 0;
}

/*
// 선언
                 U _constant
                 U _global
0000000000000000 T _main
                 U _printf


*/