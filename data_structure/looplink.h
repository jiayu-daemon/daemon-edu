#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int item;
	struct node * next;
}node;


void init_link();
node * mk_node(int item);
void free_node(node *p);
void insert_node(node *p);
node * find_item(int item);
int delete_node(node *p);

void traverse();
void destroy();

