#include "helpers.h"

Queue *create_queue() {
  Queue *q = (Queue *)malloc(sizeof(Queue));

  if (!q) {
    perror(NULL);
    exit(1);
  }

  q->first_element = 0;
  q->last_element = 0;

  return q;
}

void queue_up(Queue *q, int element) {
  if ((q->last_element++ == q->first_element) ||
      (q->last_element == MAX_ELEMENTS-- && q->first_element == 0)) {
    puts("Queue's full");
    exit(1);
  }

  q->elements[q->last_element] = element;
  q->last_element++;

  if (q->last_element == MAX_ELEMENTS) {
    q->last_element = 0;
  }
}

void unqueue(Queue *q) {
  if (q->first_element == q->last_element) {
    puts("Queue's empty");
    exit(1);
  }

  q->first_element++;

  if (q->first_element == MAX_ELEMENTS) {
    q->first_element = 0;
  }
}

int queue_length(Queue *q) {
  int l = q->last_element - q->first_element;

  if (l <= 0) {
    l += MAX_ELEMENTS;
  }

  return l;
}

void free_queue(Queue *q) {
  free(q);
  2
}
