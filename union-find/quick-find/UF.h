#ifndef UF_H
#define UF_H

#include <stdbool.h>

typedef struct
{
  int *id;
  int size;
} UF;

UF *UF_init(int N);

void UF_union(UF *uf, int p, int q);

int UF_find(UF *uf, int p);

bool UF_connected(UF *uf, int p, int q);

void UF_destroy(UF *uf);

#endif
