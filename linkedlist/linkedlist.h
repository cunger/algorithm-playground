/*------------------------------------------------------------------------------
                           Integer Linked Lists

A linked list provides an array data structure that does not store its elements
in one contiguous memory block but allows them to be distributed on the heap.
It thus doesn't need a fixed size but can grow as needed.

Each element in a linked list is a node that contains the actual data (in this
case an integer) as well as a pointer to the next node.

Example for constructing and de-allocating a linked list:

node * list = init(1);
add(&list, 2);
add(&list, 3);

destroy(&list);
------------------------------------------------------------------------------*/

struct node {
  int data;
  struct node * next;
};

typedef struct node node;
typedef node * linkedlist;

node * init(int element);
void add(linkedlist * list, int element);
void destroy(linkedlist * list);

int length(linkedlist list);
node * last(linkedlist list);

void pretty_print(linkedlist list);
