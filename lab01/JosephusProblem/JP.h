#pragma once

#include "Node.h"

typedef struct
{
  Node *head;
  int size;
} JP;

JP *JP_construct(int N);

void JP_run(JP *jp, int M);

void JP_destroy(JP *jp);
