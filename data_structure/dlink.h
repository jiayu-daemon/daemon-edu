#ifndef __DLINK_H
#define __DLINK_H


typedef struct node
{
	int item;
	struct node * pre;
	struct node * next;
}node;



node * make_node(int item);
void free_node(node *p);
node * search(int item);
void insert_node(node * p);
void delete_node(node * p);
void traverse();
void destroy(void);
void enqueue(node * p);
node * dequeue(void);




#endif


