#include "tree.h"
#include "treeInterface.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  srand(time(NULL)); //for better randomization
  Tree * tree = (Tree*) malloc(sizeof(Tree));

  int i;
  for (i = 0; i<20; i++) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value =  rand()%100;
    add(tree, node);
  }

  int depth = maxDepth(tree->head);

  printf("max depth: %d\n", depth);
  i = 0;
  while(i<=depth){
    printNodesAtLevel(tree->head,i,0, depth - i);
    printf("\n");
    i++;
  }
  return 0;
}

void add(Tree *tree, Node *node){
  if(tree==NULL || node == NULL)
    exit(0);

  if(tree->head == NULL){
    tree->head = node;
  }else{

    Node *tmp;
    Node *parent;
    tmp = tree->head;

    while(1){
      parent = tmp;
      if(tmp->value > node->value){
        if((tmp = tmp->left) == NULL){
          parent->left = node;
          return;
        }
      }else{
        if((tmp = tmp->right)==NULL){
          parent->right = node;
          return;
        }
      }
    }
  }
}

void printNodesAtLevel(Node *node, int desired, int current, int prettyprint){
   if (node)
   {
      if (desired == current){
          int space = (prettyprint) / 2;
          while(space>=0){
            printf(" ");
            space --;
          }
          printf("(%d) ",node->value);
      }
      else
      {
         printNodesAtLevel(node->right, desired, current + 1,  prettyprint);
         printNodesAtLevel(node->left, desired, current + 1,  prettyprint);
      }
   }
 }



int maxDepth(Node *node) {
    if (!node) {
        return -1;
    } else {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        if (leftDepth > rightDepth )
            return (leftDepth + 1);

        return (rightDepth + 1);
    }
}

void traverse(Node *node){
  if(node){
      //printf("\n it -- %d",node->value); //pre-order
    traverse(node->left);
      //printf("\n it -- %d",node->value); //in-order
    traverse(node->right);
      //printf("\n it -- %d",node->value); //post-order
  }
}
