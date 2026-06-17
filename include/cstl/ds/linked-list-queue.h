/*

Difference between a Static Queue and a Singly Linked List ::
https://www.geeksforgeeks.org/dsa/difference-between-a-static-queue-and-a-singly-linked-list/

Queue (with metadata)
      ┌─────────┐
 head │    ●────┼──────────────┐
      ├─────────┤              │
      │    •    │              ▼   List head
      │    •    │            ┌───┬───┐       ┌───┬───┐       ┌───┬───┐ List tail
      │    •    │            │ 1 │ ●─┼──────>│ 2 │ ●─┼──────>│ 3 │ ○ │
      └─────────┘            └───┴───┘       └───┴───┘       └───┴───┘
   Additional fields

*/

#include <stdbool.h>

/* Linked list element */

typedef struct list_ele {
  int value;
  struct list_ele *next;
} list_ele_t;

typedef struct {
  list_ele_t *head; // linked list of elements
  list_ele_t *tail;
  int size;
} queue_t;

// initialising a stack queue
queue_t *q_new();
void q_free(queue_t *q);

bool q_insert_head(queue_t *q, int v);
bool q_insert_tail(queue_t *q, int v);
bool q_remove_head(queue_t *q, int *v);

int q_size(queue_t *q);

// traverse and swap elements
void q_reverse(queue_t *q);
