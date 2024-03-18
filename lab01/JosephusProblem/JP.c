#include "JP.h"
#include <stdlib.h>
#include <stdio.h>

JP *JP_construct(int N)
{
  JP *jp = (JP *)calloc(1, sizeof(JP));
  jp->size = N;

  Node *head = node_construct(NULL, NULL, 1);
  jp->head = head;

  Node *current = head;

  for (int i = 2; i <= N; i++)
  {
    Node *n = node_construct(NULL, current, i);
    current->next = n;
    current = n;
  }

  return jp;
}

Node *_JP_iterate(JP *jp, Node *current, int M)
{
  for (int i = 1; i < M; i++)
  {
    if (current->next != NULL)
    {
      current = current->next;
    }
    else
    {
      current = jp->head;
    }
  }

  return current;
}

void _JP_remove(JP *jp, Node *toRemove)
{
  int removedValue = toRemove->value;

  if (toRemove == jp->head) // Check if is the head
  {
    jp->head = toRemove->next;
    jp->head->prev = NULL;
  }
  else
  {
    if (toRemove->next == NULL) // Check if is the back
    {
      toRemove->prev->next = NULL;
    }
    else
    {
      Node *prev = toRemove->prev;
      Node *next = toRemove->next;

      prev->next = next;
      next->prev = prev;
    }
  }

  node_destroy(toRemove);
  jp->size = jp->size - 1;
  printf("Eliminated: %d\n", removedValue);
}

void JP_run(JP *jp, int M)
{
  Node *current = jp->head;
  Node *aux;

  while (jp->size > 1)
  {

    current = _JP_iterate(jp, current, M);

    if (current->next == NULL)
    {
      aux = jp->head;
    }
    else
    {
      aux = current->next;
    }

    _JP_remove(jp, current);
    current = aux;
  }

  printf("Chosen: %d\n", jp->head->value);
}

void JP_destroy(JP *jp)
{
  free(jp->head);
  free(jp);
}
