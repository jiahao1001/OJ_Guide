#include <cstdio>
struct Node
{
	int data;
	Node *next;
};
Node *head;
int search(int i)
{
	Node *p = head->next, *q = head;
	int res = 0;
	while (p != NULL && p->data != i)
	{
		++res;
		q = p;
		p = p->next;
	}
	if (p != NULL)
	{
		++res;
		q->next = p->next;
		p->next = head->next;
		head->next = p;
	}
	return res;
}
int main()
{
	int n, m, i, res = 0, t;
	head = new Node;
	head->next = NULL;
	Node *p = head, *q;
	scanf("%d", &n);
	for (i = 0; i<n; ++i)
	{
		q = new Node;
		q->next = NULL;
		scanf("%d", &(q->data));
		p->next = q;
		p = q;
	}
	scanf("%d", &m);
	for (i = 0; i<n; ++i)
	{
		scanf("%d", &t);
		res += search(t);
	}
	printf("%d", res);
}
