#include "helpers.h"

Stack *create_stack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));

  if (!s) {
    perror(NULL);
    exit(1);
  }

  s->top_element = 0;

  return s;
}

void stack_up(Stack *s, int e) {
  if (MAX_ELEMENTS == s->top_element) {
    puts("Stack's full");
    exit(1);
  }

  s->elements[s->top_element] = e;
  s->top_element++;
}

void unstack(Stack *s) {
  if (s->top_element == 0) {
    puts("Stack's already empty");
    exit(1);
  }

  s->top_element--;
}

int stack_length(Stack *s) { return s->top_element; }

void free_stack(Stack *s) { free(s); }
