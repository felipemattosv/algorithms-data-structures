#include "ES.h"
#include <stdlib.h>
#include <stdio.h>

ES *ES_construct(int N)
{
  ES *es = (ES *)calloc(1, sizeof(ES));

  es->size = N;
  es->elements = (bool *)calloc(N, sizeof(bool));

  es->elements[0] = NOT_PRIME;
  es->elements[1] = NOT_PRIME;

  return es;
}

void ES_mark(ES *es, int primo)
{
  int i = primo * 2;
  int j = 3;
  while (i < es->size)
  {
    es->elements[i] = NOT_PRIME;

    i = primo * j;
    j++;
  }
}

int ES_findNextPrime(ES *es, int lastPrime)
{
  for (int i = lastPrime + 1; i < es->size; i++)
  {
    if (es->elements[i] == PRIME)
    {
      return i;
    }
  }

  return -1;
}

void ES_result(ES *es)
{
  printf("\nPRIMES:\n");

  for (int i = 0; i < es->size; i++)
  {
    if (es->elements[i] == PRIME)
    {
      printf("%d\n", i);
    }
  }
}

void ES_destroy(ES *es)
{
  free(es->elements);
  free(es);
}
