#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;

#define MAX_ELEMENTS 10

struct Queue {
  int elements[MAX_ELEMENTS];
  int first_element;
  int last_element;
}

Queue* create_queue();
void queue_up(Queue* q, int element);
void unqueue(Queue* q);
int queue_length(Queue* q);
void free_queue(Queue* q);
