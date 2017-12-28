#include <cstdio>
struct tree
{
	int data;
	tree *left, *right;
};
void clear(tree*& t)
{
	if (t->left != NULL) clear(t->left);
	if (t->right != NULL) clear(t->right);
	delete t;
}
class bernoulli
{
private:
	tree* forest[20];
public:
	bernoulli() { for (int i = 0; i<20; ++i) forest[i] = NULL; }
	bernoulli(const bernoulli& other) { for (int i = 0; i<20; ++i) forest[i] = other.forest[i]; }
	~bernoulli() { for (int i = 0; i<20; ++i) if (forest[i] != NULL) clear(forest[i]); }
	void add(tree*& t, int pos);
	void remove();
	int min()
	{
		int t = 0, i;
		while (forest[t] == NULL) ++t;
		for (i = t + 1; i<20; ++i) if (forest[i] != NULL && forest[i]->data < forest[t]->data) t = i;
		return forest[t]->data;
	}
	void add(int value)
	{
		tree *tmp = new tree;
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->data = value;
		add(tmp, 0);
	}
};
void bernoulli::add(tree*& t, int pos)
{
	if (forest[pos] == NULL)
	{
		forest[pos] = t;
		return;
	}
	if (pos == 0)
	{
		if (forest[pos]->data < t->data)
		{
			forest[pos]->left = t;
			t = forest[pos];
			forest[pos] = NULL;
			add(t, 1);
		}
		else
		{
			t->left = forest[pos];
			forest[pos] = NULL;
			add(t, 1);
		}
		return;
	}
	tree *tmp;
	int i;
	if (forest[pos]->data < t->data)
	{
		tmp = forest[pos]->left;
		for (i = 1; i<pos; ++i) tmp = tmp->right;
		tmp->right = t;
		t = forest[pos];
		forest[pos] = NULL;
		add(t, pos + 1);
	}
	else
	{
		tmp = t->left;
		for (i = 1; i<pos; ++i) tmp = tmp->right;
		tmp->right = forest[pos];
		forest[pos] = NULL;
		add(t, pos + 1);
	}
}
void bernoulli::remove()
{
	int t = 0, i;
	while (forest[t] == NULL) ++t;
	for (i = t + 1; i<20; ++i) if (forest[i] != NULL && forest[i]->data < forest[t]->data) t = i;
	tree *tmp = forest[t]->left, *q;
	delete forest[t];
	forest[t] = NULL;
	for (i = 0; i<t; ++i)
	{
		q = tmp->right;
		tmp->right = NULL;
		add(tmp, i);
		tmp = q;
	}
}
int main()
{
	//freopen("1215.in","r",stdin);
	int n, i, t;
	char ss[10];
	scanf("%d", &n);
	bernoulli que;
	for (i = 0; i<n; ++i)
	{
		scanf("%s", ss);
		if (ss[0] == 'i')
		{
			scanf("%d", &t);
			que.add(t);
		}
		else if (ss[0] == 'm')
		{
			printf("%d\n", que.min());
		}
		else que.remove();
	}
}
