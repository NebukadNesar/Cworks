#ifndef STACK_H_HEADER
#define STACK_H_HEADER
typedef struct Node_T {
  struct Node_T *prev;
  int value;
} node;

typedef struct Stack {
  node *last;
} stack;
#endif
