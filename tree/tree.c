#include "tree.h"
#include "treeInterface.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define COUNT 10

void prettyPrintTree(Tree *tree);
void poopulateTreeWithRandomValues(Tree *tree);

int main(int argc, char const *argv[]) {

  Tree *tree = (Tree*) malloc(sizeof(Tree));
  poopulateTreeWithRandomValues(tree);
  prettyPrintTree(tree);
  traverse(tree->head);

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

void printNodesAtLevel(Node *node, int desired, int current, int depth, Tree *tree){

   if (node)
   {  //printf("pretty: %d\n", node->value);
      if (desired == current){
         if(tree->pretty.print == 0){  // 0 => Y, 1 => N
            int space = depth - current;
            while(space>=0){
              printf(" ");
              space --;
            }
          }
          if(tree->pretty.print == 1){
            printf(",");
          }
          printf("(%d)",node->value);
          if(tree->pretty.print == 0){
            tree->pretty.print = 1;
          }
      }
      else
      {
          printNodesAtLevel(node->right, desired, current + 1,  depth, tree);
          printNodesAtLevel(node->left, desired, current + 1,  depth, tree);
      }
   }
}

void prettyPrintTree(Tree *tree){
  int depth = maxDepth(tree->head);

  int i = 0;
  while(i<=depth){
    tree->pretty.print = 0;
    printNodesAtLevel(tree->head, i ,0 ,depth, tree);
    printf("\n");
    i++;
  }
}


void poopulateTreeWithRandomValues(Tree *tree){
  srand(time(NULL)); //for better randomization
  int i;
  for (i = 0; i<20; i++) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value =  rand()%100;
    add(tree, node);
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
      // printf("\n it -- %d",node->value); //pre-order
    traverse(node->left);
      // printf("\n it -- %d",node->value); //in-order
    traverse(node->right);
      // printf("\n it -- %d",node->value); //post-order
  }
}
