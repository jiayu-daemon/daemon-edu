#include <stdio.h>
#include <stdlib.h>
#include "dlink.h"


struct node tail_sentinel;
struct node head_sentinel = {0,NULL,&tail_sentinel};
struct node tail_sentinel = {0,&head_sentinel,NULL};

static node * head = &head_sentinel;
static node * tail = &tail_sentinel;


node * make_node(int item)
{
	node * p = malloc(sizeof*p);
	if(p == NULL){
		return NULL;
	}

	p->item = item;
	p->pre = p->next = NULL;

	return p;
}


void free_node(node *p )
{
	free(p);
}


node * search(int item)
{
	node *p;
	for(p = head->next; p != tail; p = p->next){
		if(p->item == item){
			return p;
		}
	}
	return NULL;
}


void insert_node(node * p)
{
	p->next = head->next;
	head->next->pre = p;
	head->next = p;
	p->pre = head;
}



void delete_node(node * p)
{

	p->pre->next = p->next;
	p->next->pre = p->pre;
}


void traverse()
{
	node * p;
	for(p = head->next; p != tail; p = p->next){
		printf("%d ", p->item);
	}
	printf("\n");
}


void destroy(void)
{
	node *q;
	node *p = head->next;

	head->next = tail;
	tail->pre = head;

	while(p != tail)
	{
		q = p;
		p = p->next;
		free_node(q);
	}
}

void enqueue(node * p)
{
	insert_node(p);
}


node * dequeue(void)
{
	if(tail->pre == head){
		return NULL;
	}
	else{
		node * p = tail->pre;
		delete_node(p);
		return p;
	}
}


int main(void)
{

	node *p = make_node(10);
	insert_node(p);

	p= make_node(5);
	insert_node(p);

	p = make_node(90);
	insert_node(p);

	traverse();

	p = search(5);
	delete_node(p);
	free_node(p);

	traverse();
	destroy();

	p = make_node(2);
	enqueue(p);

	p = make_node(5);
	enqueue(p);

	p = make_node(10);
	enqueue(p);

	while(p = dequeue())
	{
		printf("%d ", p->item);
		free_node(p);
	}
	printf("\n");

	return 0;

}