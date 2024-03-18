#include <stdio.h>
#include "ES.h"

int main()
{
  int N;
  int prime = 2;

  scanf("%d", &N);
  ES *es = ES_construct(N);

  while (1)
  {
    ES_mark(es, prime);
    prime = ES_findNextPrime(es, prime);

    if (prime == -1)
    {
      break;
    }
  }

  ES_result(es);

  ES_destroy(es);

  return 0;
}
