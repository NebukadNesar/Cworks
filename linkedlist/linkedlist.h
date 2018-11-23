#ifndef LINKKEDLIST
#define LINKKEDLIST
typedef struct NODE_L{
	int value;
	struct NODE_L *link;
	
} LNode;


typedef struct L_L {
	
	LNode *head;
	LNode *last;

} LinkedList;
#endif