// b.c

// 정의
int global = 0;

#if defined(__cplusplus)
extern const int constant = 100;
#else
const int constant = 100;
#endif

#if 0
// 정의

0000000000000000 S _constant
0000000000000004 S _global
#endif