#include <stdio.h>
#include <stdlib.h>

#include "linked-list-queue.h"

queue_t *q_new() {
  queue_t *q = malloc(sizeof(queue_t));

  if (q == NULL) {
    return NULL;
  }

  q->head = NULL;
  q->tail = NULL;
  q->size = 0;

  return q;
}

void q_free(queue_t *q) {
  if (q == NULL) {
    return;
  }

  list_ele_t *current = q->head;
  while (current != NULL) {
    list_ele_t *next_node = current->next;
    free(current);
    current = next_node;
  }

  free(q);
}

bool q_insert_head(queue_t *q, int v) {
  if (q == NULL) {
    return false;
  }

  list_ele_t *nd = malloc(sizeof(list_ele_t));
  if (nd == NULL) {
    return false;
  }
  nd->value = v;
  nd->next = q->head;

  if (q->head == NULL) {
    q->tail = nd;
  }
  q->head = nd;
  q->size += 1;

  return true;
}

bool q_insert_tail(queue_t *q, int v) {
  if (q == NULL) {
    return false;
  }

  list_ele_t *nd = malloc(sizeof(list_ele_t));
  if (nd == NULL) {
    return false;
  }
  nd->value = v;
  nd->next = NULL;

  if (q->head == NULL) {
    q->head = nd;
    q->tail = nd;
  } else {
    q->tail->next = nd;
    q->tail = nd;
  }
  q->size += 1;

  return true;
}

bool q_remove_head(queue_t *q, int *v) {
  if (q == NULL || q->head == NULL) {
    return false;
  }

  list_ele_t *p_head = q->head;
  if (v != NULL) {
    *v = p_head->value;
  }
  q->head = q->head->next;
  if (q->head == NULL) {
    q->tail = NULL;
  }

  free(p_head);
  q->size -= 1;

  return true;
}

int q_size(queue_t *q) {
  if (q == NULL) {
    return 0;
  }

  return q->size;
}

void q_reverse(queue_t *q) {
  if (q == NULL || q->head == NULL) {
    return;
  }

  list_ele_t *items = q->head->next;
  q->tail = q->head;

  while (items != NULL) {
    list_ele_t *current = items;
    items = items->next;
    current->next = q->head;
    q->head = current;
  }

  q->tail->next = NULL;
}
