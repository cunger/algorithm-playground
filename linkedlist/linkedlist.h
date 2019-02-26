/*------------------------------------------------------------------------------
                           Integer Linked Lists

A linked list provides an array data structure that does not store its elements
in one contiguous memory block but allows them to be distributed on the heap.
It thus doesn't need a fixed size but can grow as needed, and it allows for
insertion and deletion without the need of shifting subsequent elements.

Each element in a linked list is a node that contains the actual data (in this
case an integer) as well as a pointer to the next node.

Example for constructing and de-allocating a linked list:

linkedlist list = init(1);
add(2, &list);
add(3, &list);

destroy(&list);
------------------------------------------------------------------------------*/

struct node {
  int data;
  struct node* next;
};

typedef struct node node;
typedef node* linkedlist;

linkedlist list(int size, int element, ...);

node* init(int element);
void add(int element, linkedlist list);
void insert_after(int index, int element, linkedlist list);

node* get(int index, linkedlist list);
node* last(linkedlist list);

void move(int old_index, int new_index, linkedlist* list);

void delete(int index, linkedlist* list);
void destroy(linkedlist* list);

int length(linkedlist list);

void pretty_print(linkedlist list);

void sort(linkedlist* sequence);
