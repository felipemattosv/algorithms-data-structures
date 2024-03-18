#include "Node.h"
#include <stdlib.h>

Node *node_construct(Node *next, Node *prev, int value)
{
  Node *n = (Node *)calloc(1, sizeof(Node));

  n->next = next;
  n->prev = prev;
  n->value = value;

  return n;
}

void node_destroy(Node *n)
{
  free(n);
}
