#include <iostream>
using namespace std;
struct node
{
	unsigned short data;
	node *prev, *next;
};
void clear(node *x)
{
	node *p = x;
	while (((p->next) != NULL))
	{
		p = p->next;
		delete (p->prev);
	}
	delete p;
}
int main()
{
	node *a = new node, *b, *c, *d, *x, *y, *z;
	char t;
	cin.get(t);
	a->data = t - '0';
	a->prev = NULL;
	a->next = NULL;
	cin.get(t);
	while (t != '\n')
	{
		b = new node;
		b->data = t - '0';
		a->prev = b;
		b->next = a;
		b->prev = NULL;
		a = b;
		cin.get(t);
	}
	x = a;
	a = new node;
	cin.get(t);
	a->data = t - '0';
	a->prev = NULL;
	a->next = NULL;
	cin.get(t);
	while (t != '\n')
	{
		b = new node;
		b->data = t - '0';
		a->prev = b;
		b->next = a;
		b->prev = NULL;
		a = b;
		cin.get(t);
	}
	y = a;
	/*y=a;
	a->next=NULL;
	while (cin>>t)
	{
	b=new node;
	b->data=t-'0';
	a->prev=b;
	b->next=a;
	b->prev=NULL;
	a=b;
	}
	y=y->prev;
	delete (y->next);
	y->next=NULL;
	y=a;*/
	z = new node;
	z->data = (x->data) + (y->data);
	z->prev = NULL;
	c = z; a = x->next; b = y->next;
	while ((a != NULL) && (b != NULL))
	{
		d = new node;
		d->data = (a->data) + (b->data);
		d->prev = c;
		c->next = d;
		d->next = NULL;
		c = d;
		a = a->next;
		b = b->next;
	}
	if ((a == NULL) && (b != NULL))
	{
		c->next = b;
		b->prev->next = NULL;
		b->prev = c;
	}
	else if ((b == NULL) && (a != NULL))
	{
		c->next = a;
		a->prev->next = NULL;
		a->prev = c;
	}
	clear(x); clear(y);
	unsigned short i = 0;
	for (c = z; c != NULL; c = c->next)
	{
		c->data += i;
		i = (c->data) / 10;
		c->data %= 10;
		d = c;
	}
	if (i>0)
	{
		c = new node;
		c->data = i;
		c->prev = d;
		c->next = NULL;
		d->next = c;
		d = c;
	}
	for (c = d; c != NULL; c = c->prev) cout << (c->data);
	clear(z);
	return 0;
}
