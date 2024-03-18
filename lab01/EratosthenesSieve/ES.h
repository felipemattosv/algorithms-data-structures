#pragma once

#include <stdbool.h>

#define NOT_PRIME 1
#define PRIME 0

typedef struct
{
  int size;
  bool *elements;
} ES;

ES *ES_construct(int N);

int ES_findNextPrime(ES *es, int lastPrime);

void ES_mark(ES *es, int prime);

void ES_result(ES *es);

void ES_destroy(ES *es);
