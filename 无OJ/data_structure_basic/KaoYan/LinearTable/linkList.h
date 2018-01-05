#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode, *LinkList;

LinkList createLinkList(void)
{
	LNode * result;
	result = (LinkList)malloc(sizeof(LNode));
	int num = 0;
	LNode *s, *rear;
	rear = result;
	FILE *f = fopen("nums.data", "r");
	for (int i = 0; i < 100 - 1; ++i) {
		num = getw(f);
		s = (LinkList)malloc(sizeof(LNode));
		s->data = num;
		s->next = NULL;
		rear->next = s;
		rear = s;
	}
	fclose(f);
	result->data = 99;
	return result;
}

void printLinkList(LinkList l)
{
	if (l == NULL){
		printf("This linklist is NULL\n");
		return;
	}
	while(l->next != NULL)
	{
		l = l->next;
		printf("%d ", l->data);
	}
	printf("\n");
}

void deleteLinkList(LinkList l)
{
	LNode *p;
	while(l != NULL) {
		p = l;
		l = l->next;
		free(p);
	}
}

typedef struct DoubleNode
{
	int data;
	int freq;
	struct DoubleNode *pre, *next;
} DoubleNode, *DoubleList;

DoubleList createDoubleList(void)
{
	DoubleNode * result = (DoubleList)malloc(sizeof(DoubleNode));
	int num = 0;
	DoubleNode *t;
	FILE *f = fopen("nums.data", "r");
	for (int i = 0; i < 100 - 1; ++i) {
		num = getw(f);
		t = (DoubleList)malloc(sizeof(DoubleNode));
		t->data = num;
		t->next = result->next;
		// 插入第一个节点时，是一个特使节点NULL没有pre
		if (result->next != NULL)
			result->next->pre = t;
		t->pre = result;
		result->next = t;
	}
	fclose(f);

	return result;
}
void printDoubleList(DoubleList d)
{
	DoubleList t = d->next, pre;
	while(t != NULL) {
		printf("%d ", t->data);
		pre = t;
		t = t->next;
	}
	printf("\n");
	printf("pre \n");
	while (pre != d) {
		printf("%d ", pre->data);
		pre = pre->pre;
	}
	printf("\n");
}

void printDoubleFreq(DoubleList d)
{
	printf("Freq of d\n");
	DoubleList t = d->next;
	while(t != NULL) {
		printf("%d ", t->freq);
		t = t->next;
	}
	printf("\n");
}