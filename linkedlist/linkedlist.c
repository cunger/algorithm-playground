#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#include "linkedlist.h"

linkedlist list(int size, int element, ...) {
  node* head = init(element);

  va_list tail;
  va_start(tail, element);

  int i;
  for (i = 0; i < size - 1; i++) {
    int next_element = va_arg(tail, int);
    add(next_element, head);
  }

  va_end(tail);

  return head;
}

node* init(int element) {
  node* new_node = malloc(sizeof(node));
  assert(new_node != NULL);

  new_node->data = element;
  new_node->next = NULL;

  return new_node;
}

node* last(linkedlist list) {
  node* n = list;
  while (n->next) {
    n = n->next;
  }

  return n;
}

node* get(int index, linkedlist list) {
  if (index < 0) return NULL;

  node* n = list;

  int i = 0;
  while (i < index) {
    if (!n->next) return NULL;

    n = n->next;
    i++;
  }

  return n;
}

void add(int element, linkedlist list) {
  node* new_node = init(element);

  (last(list))->next = new_node;
}

void insert_after(int index, int element, linkedlist list) {
  node* node_before = get(index, list);
  node* node_after  = get(index + 1, list);

  if (node_before == NULL) return;

  node* new_node = init(element);
  if (node_after != NULL) {
    new_node->next = node_after;
  }

  node_before->next = new_node;
}

void delete(int index, linkedlist* list) {
  if (index == 0) {
    node* first_node = *list;
    *list = (*list)->next;
    free(first_node);
    return;
  }

  node* this_node   = get(index, *list);
  node* node_before = get(index - 1, *list);
  node* node_after  = get(index + 1, *list);

  if (node_before == NULL) return;

  if (this_node != NULL) {
    free(this_node);
    node_before->next = node_after;
  }
}

void move(int old_index, int new_index, linkedlist* list) {
  if (new_index == old_index) return;

  node* this_node  = get(old_index, *list);
  node* new_after  = get(new_index, *list);
  node* new_before = get(new_index - 1, *list);
  node* old_after  = get(old_index + 1, *list);
  node* old_before = get(old_index - 1, *list);

  if (new_before == NULL) { // i.e. new_index == 0
    *list = this_node;
  } else {
    new_before->next = this_node;
  }

  this_node->next  = new_after;

  if (old_before == NULL) { // i.e. old_index == 0
    *list = old_after;
  } else {
    old_before->next = old_after;
  }
}

void destroy(linkedlist* list) {
  node* curr_node = *list;
  node* next_node;

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

void sort(linkedlist* sequence) {
  /*
  Iterate over all nodes, starting at index 1.
  */
  int index;
  for (index = 1; ; index++) {
    node* this_node = get(index, *sequence);

    /*
    As soon as we hit the end of the input sequence, stop.
    */
    if (this_node == NULL) return;

    /*
    Subsequence before this node is already sorted. So find the position
    in the subsequence where this node needs to be inserted.
    */
    int new_index = 0;
    node* n = *sequence;
    while (n != NULL && n->data < this_node->data) {
      n = n->next;
      new_index++;
    }

    /*
    Move element from current index to new index.
    */
    move(index, new_index, sequence);
  }
}
