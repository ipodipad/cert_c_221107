// 0_QA.c

int main(void)
{
  int nRetry = 5;
  // while (nRetry--) /* NO */

  while (nRetry-- > 0) /* OK */
  {
  }

  return 0;
}
