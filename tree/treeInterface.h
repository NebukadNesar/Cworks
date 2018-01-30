#ifndef TREE_INTERFACE_H
#define TREE_INTERFACE_H
void add(Tree *t, Node *n);
void search(Tree *t, int value);
void deleteNode(Tree *t, int value);
void deleteTree(Tree *t);
void traverse(Node *n);
void printNodesAtLevel(Node *node, int desired, int current, int prettyprint);
int maxDepth(Node *n);
#endif
