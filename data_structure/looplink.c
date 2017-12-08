#include "looplink.h"

static node head_sentinel ={0,NULL};
node * head = NULL;

void init_link()
{
	head = &head_sentinel;
	head_sentinel.next = head;
}


node * mk_node(int item)
{
	node *p = (node *)malloc(sizeof(node));
	if(p == NULL){
		printf("malloc failed\n");
		return NULL;
	}

	p->item = item;
	p->next = NULL;

	return p;
}


void free_node(node * p)
{
	free(p);
}


void insert_node(node * p)
{
	p->next = head->next;
	head->next = p;
}

node * find_item(int item)
{
	node *p = head->next;
	while(p != NULL)
	{
		if(p->item == item){
			return p;
		}
		p = p->next;
	}

	return NULL;
}


int delete_node(node *p)
{

	node *pre = head;
	while( pre->next  != head){
		if(pre->next == p){
			pre->next = p->next;
			return 1;
		}
		pre = pre->next;
	}

	return 0;
}

void traverse()
{
	node *p = head->next;
	printf("traverse:");
	while(p != head)
	{
		printf("%d ", p->item);
		p = p->next;
	}
	printf("\n");
}


void destroy()
{
	node *p = head->next;

	printf("destroy:");
	while(p != head)
	{
		printf("%d ",p->item);
		delete_node(p);
		free_node(p);
		p = p->next;
	}
	printf("\n");
}


int main()
{

	init_link();

	node *p = mk_node(1);
	insert_node(p);
	traverse();

	p = mk_node(2);
	insert_node(p);
	traverse();


	p = mk_node(4);
	insert_node(p);
	traverse();

	p = find_item(4);
	delete_node(p);
	free_node(p);
	traverse();

	destroy();


	return 0;

}