#include "stack.h"
#include "stackInterface.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  stack *s = (stack*)malloc(sizeof(stack));

  int i = 0;

  for (i = 0; i < 10; i++) {
    node *n = (node*)malloc(sizeof(node));
    n->prev = NULL;
    n->value = i;
    push(n,s);
  }
  pop(s);
  pop(s);
  pop(s);
  pop(s);

  return 0;
}

void push(node *n, stack *s){
    if(n==NULL || s==NULL){
      printf("exiting...\n");
      exit(0);
    }

    if(s->last == NULL){
       s->last = n;
    }else{
       printf("node:%d\n", n->value);
       printf("stack last: %d\n", s->last->value);
       n->prev = s->last;
       s->last = n;
    }
}

void pop(stack *stack){
  if (stack!=NULL && stack->last!=NULL) {
    printf("to be deleted: %d\n", stack->last->value);
    node *tmp = stack->last;
    stack->last = stack->last->prev;
    free(tmp);
  }else{
    printf("stack is empty\n");
  }
}
