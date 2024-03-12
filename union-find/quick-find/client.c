#include <stdio.h>
#include <stdlib.h>
#include "UF.h"

int main(int argc, char *argv[])
{
  int p, q, breakFlag, N = atoi(argv[1]);
  UF *uf = UF_init(N);

  while (1)
  {
    scanf("%d %d", &p, &q);

    if (!UF_connected(uf, p, q))
    {
      UF_union(uf, p, q);
      printf("%d %d\n", p, q);
    }

    printf("Continue? (yes: 1 / no: 0): ");
    scanf("%d", &breakFlag);

    if (!breakFlag)
    {
      break;
    }
  }

  UF_destroy(uf);

  return 0;
}
