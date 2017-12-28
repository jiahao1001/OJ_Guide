#include <iostream>
#include <cstring>
using namespace std;
struct letter
{
	char content;
	letter *right;
};
struct node
{
	int length;
	letter* data;
	node *prev, *next;
};
class article
{
private:
	node *head, *tail;
	int lineNum;
public:
	article();
	void addLine(const char *s);
	void list(int start, int end);
	void ins(int line, int colomn, const char *s);
	void del(int line, int colomn, int del_len);
	void print() { if (lineNum>0) (*this).list(1, lineNum); }
	~article();
};
article::article()
{
	lineNum = 0;
	head = new node;
	tail = new node;
	head->prev = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->prev = head;
}
void article::addLine(const char *s)
{
	node *p = new node;
	p->length = strlen(s);
	p->data = new letter;
	p->data->right = NULL;
	letter *pp = p->data, *q; int i;
	for (i = 0; i<(p->length); ++i)
	{
		q = new letter;
		q->content = s[i];
		pp->right = q;
		pp = q;
	}
	pp->right = NULL;
	p->next = tail;
	p->prev = (tail->prev);
	(tail->prev)->next = p;
	(tail->prev) = p;
	++lineNum;
}
void article::list(int start, int end)
{
	if ((start <= 0) || (end>lineNum) || (start>end))
	{
		cout << "Error!" << endl;
		return;
	}
	int i; node *p = head; letter *q;
	for (i = 0; i<start; ++i) p = p->next;
	for (i = 0; i<end - start + 1; ++i)
	{
		for (q = (p->data)->right; q != NULL; q = q->right) cout << (q->content);
		cout << endl;
		p = p->next;
	}
}
void article::ins(int line, int colomn, const char *s)
{
	if ((line <= 0) || (line>lineNum) || (colomn <= 0))
	{
		cout << "Error!" << endl;
		return;
	}
	int i; node *p = head;
	for (i = 0; i<line; ++i) p = p->next;
	if (colomn>(p->length + 1))
	{
		cout << "Error!" << endl;
		return;
	}
	letter *q = new letter, *r, *m = q;
	q->right = NULL;
	int ll = strlen(s);
	p->length += ll;
	for (i = 0; i<ll; ++i)
	{
		r = new letter;
		r->content = s[i];
		q->right = r;
		q = r;
	}
	q->right = NULL;
	q = p->data;
	for (i = 0; i<colomn - 1; ++i) q = q->right;
	r->right = q->right;
	q->right = m->right;
	delete m;
}
void article::del(int line, int colomn, int del_len)
{
	if (del_len <= 0) return;
	if ((line <= 0) || (line>lineNum) || (colomn <= 0))
	{
		cout << "Error!" << endl;
		return;
	}
	int i; node *p = head;
	for (i = 0; i<line; ++i) p = p->next;
	if (colomn + del_len - 1>(p->length))
	{
		cout << "Error!" << endl;
		return;
	}
	p->length -= del_len;
	letter *q = p->data, *r, *m;
	for (i = 0; i<colomn - 1; ++i) q = q->right;
	r = q; m = q->right;
	for (i = 0; i<del_len; ++i) r = r->right;
	q->right = r->right;
	r->right = NULL;
	while (m->right != NULL)
	{
		r = m;
		m = m->right;
		delete r;
	}
	delete m;
}
article::~article()
{
	node *p = head, *m; letter *q, *r;
	while (p != tail)
	{
		if (p != head)
		{
			q = p->data;
			while (q->right != NULL)
			{
				r = q;
				q = q->right;
				delete r;
			}
		}
		m = p;
		p = p->next;
		delete m;
	}
	delete p;
}
int main()
{
	char s[2000]; article art; int a, b, c;
	char st[100];
	cin.getline(s, 2000);
	while (strcmp(s, "******") != 0)
	{
		art.addLine(s);
		cin.getline(s, 2000);
	}
	cin >> s;
	while (strcmp(s, "quit") != 0)
	{
		if (strcmp(s, "list") == 0)
		{
			cin >> a >> b;
			art.list(a, b);
		}
		else if (strcmp(s, "ins") == 0)
		{
			cin >> a >> b;
			cin.get();
			cin.getline(st, 100);
			art.ins(a, b, st);
		}
		else if (strcmp(s, "del") == 0)
		{
			cin >> a >> b >> c;
			art.del(a, b, c);
		}
		cin >> s;
	}
	art.print();
}
