#pragma once

typedef struct Node
{
  int value;
  struct Node *next;
  struct Node *prev;
} Node;

Node *node_construct(Node *next, Node *prev, int value);

void node_destroy(Node *n);
