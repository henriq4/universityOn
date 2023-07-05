#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;

#define MAX_ELEMENTS 10

struct Stack {
  int elements[MAX_ELEMENTS];
  int top_element;
}

Stack* create_stack();
void stack_up(Stack* s, int e);
void unstack(Stack* s);
int stack_length(Stack* s);
void free_stack(Stack* s);
