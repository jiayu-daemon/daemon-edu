#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int item;
	struct node * next;
}node;

node * mk_node(int item);
void free_node(node *p);
void insert(node *p);
void insert_sort_l2b(node * p);
void traverse();
node * find(int item);
int delete_node(node * p);
void destroy();
void reverse();


