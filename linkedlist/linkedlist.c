#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linkedlist.h"

node * init(int element) {
  node * new_node = malloc(sizeof(node));
  assert(new_node != NULL);

  new_node->data = element;
  new_node->next = NULL;

  return new_node;
}

node * last(linkedlist list) {
  node * n = list;
  while (n->next) {
    n = n->next;
  }

  return n;
}

void add(linkedlist * list, int element) {
  node * new_node = init(element);

  (last(*list))->next = new_node;
}

void destroy(linkedlist * list) {
  node * curr_node = *list;
  node * next_node;

  while (curr_node->next) {
    next_node = curr_node->next;
    free(curr_node);
    curr_node = next_node;
  }

  free(curr_node);
}

int length(linkedlist list) {
  int count = 0;

  linkedlist current = list;
  while (current) {
    ++count;
    current = current->next;
  }

  return count;
}

void pretty_print(linkedlist list) {
  printf("{");

  linkedlist current = list;
  while (current) {
    printf("%d", current->data);

    if (current->next) {
      printf(", ");
    }

    current = current->next;
  }

  printf("}\n");
}
