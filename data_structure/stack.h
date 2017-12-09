#ifndef __STACK_H
#define __STACK_H


#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int item;
	struct node * next;
}node;

node * mk_node(int item);
void free_node(node * p);
void insert(node * p);
void traverse();
node * find(int item);
int delete_node(node * p);
void destroy();
void push(int);
int pop();
int is_empty();

#endif


