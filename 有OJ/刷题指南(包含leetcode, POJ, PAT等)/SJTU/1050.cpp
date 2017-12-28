#include <cstdio>
struct Tree
{
	int value;
	Tree *left, *right;
};
Tree*& combine(Tree* &a, Tree* &b)
{
	if (a == NULL && b == NULL) return a;
	if (a == NULL) return b;
	if (b == NULL) return a;
	Tree *tmp;
	if (a->value > b->value)
	{
		b->right = combine(b->right, a);
		tmp = b->left;
		b->left = b->right;
		b->right = tmp;
		return b;
	}
	else
	{
		a->right = combine(a->right, b);
		tmp = a->left;
		a->left = a->right;
		a->right = tmp;
		return a;
	}
}
void push(Tree* &a, int v)
{
	Tree *tmp = new Tree;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->value = v;
	a = combine(a, tmp);
}
void pop(Tree* &a)
{
	if (a == NULL)
	{
		printf("-1\n");
		return;
	}
	Tree *l = a->left, *r = a->right;
	printf("%d\n", a->value);
	delete a;
	a = combine(l, r);
}
int main()
{
	int n, m, i;
	scanf("%d %d", &n, &m);
	Tree **forest = new Tree*[n];
	for (i = 0; i<n; ++i)
	{
		forest[i] = new Tree;
		forest[i]->left = NULL;
		forest[i]->right = NULL;
		scanf("%d", &(forest[i]->value));
	}
	int flag, a, b;
	for (i = 0; i<m; ++i)
	{
		scanf("%d", &flag);
		if (flag == 0)
		{
			scanf("%d %d", &a, &b);
			forest[a] = combine(forest[a], forest[b]);
			forest[b] = NULL;
		}
		else
		{
			scanf("%d", &a);
			if (flag == 1) pop(forest[a]);
			else
			{
				scanf("%d", &b);
				push(forest[a], b);
			}
		}
	}
}
