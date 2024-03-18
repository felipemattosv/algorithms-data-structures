#include <stdlib.h>
#include <stdio.h>
#include "JP.h"

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s N M\n", argv[0]);
    return 1;
  }

  int N = atoi(argv[1]);
  int M = atoi(argv[2]);

  JP *jp = JP_construct(N);
  JP_run(jp, M);
  JP_destroy(jp);

  return 0;
}
