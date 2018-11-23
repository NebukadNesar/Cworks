#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "linkedlistInterface.h"

int main(int argc, char const *argv[])
{
	 
	LinkedList *L = (LinkedList *) malloc(sizeof(LinkedList));
    for (int i = 0; i < 10; ++i)
    {
    	  addi(L, i);
    }

    iteratei(L);
    deletei(L,4);
    deletei(L,6);
    iteratei(L);

	return 0;
}

void addi(LinkedList *l, int val){
	LNode *lnode = (LNode*) malloc(sizeof(LNode));
	lnode->value = val;
    lnode->link = NULL;

    if(l->head == NULL){
    	l->head = lnode;
    }else{
    	LNode *temp = l->head;
    	while(temp->link != NULL){
    		temp = temp->link;
    	}
    	temp->link = lnode;
    }

    printf("to be addi %d\n", val);
}

void deletei(LinkedList *l, int val){
 	 printf("to be deletei %d\n", val);
 	if(l->head == NULL){
    	printf("empty list ..");
    }else{
    	LNode *temp = l->head;
    	LNode *prev = l->head;
    	while(temp != NULL){
    		if (temp->value == val)
    		{
    			prev->link = temp->link;
    		}
    		prev = temp;
    		temp = temp->link;
    	}
    }
}

void iteratei(LinkedList *l){

    if(l->head == NULL){
    	printf("empty list ..\n");
    }else{
    	LNode *temp = l->head;
    	while(temp != NULL){
    		printf("to be ite: %d \n", temp->value);
    		temp = temp->link;
    	}
    }
     printf("iteración\n");
}