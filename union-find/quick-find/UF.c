#include "UF.h"
#include <stdlib.h>

UF *UF_init(int N)
{
  UF *uf = (UF *)malloc(1 * sizeof(UF));

  uf->size = N;
  uf->id = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++)
  {
    uf->id[i] = i;
  }

  return uf;
}

void UF_union(UF *uf, int p, int q)
{
  int pid = UF_find(uf, p);
  int qid = UF_find(uf, q);

  uf->id[p] = qid;

  for (int i = 0; i < uf->size; i++)
  {
    if (UF_find(uf, i) == pid)
    {
      uf->id[i] = qid;
    }
  }
}

int UF_find(UF *uf, int p)
{
  return uf->id[p];
}

bool UF_connected(UF *uf, int p, int q)
{
  return UF_find(uf, p) == UF_find(uf, q);
}

void UF_destroy(UF *uf)
{
  free(uf->id);
  free(uf);
}
