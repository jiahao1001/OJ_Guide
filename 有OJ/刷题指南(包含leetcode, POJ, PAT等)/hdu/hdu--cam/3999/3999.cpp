#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<cstdlib>

using namespace std;

struct Tree{
	Tree *l, *r;
	int x;
}tree;

Tree *root;
Tree *Creat(Tree *rt, int x){
	if(rt == NULL){
		rt = (Tree *)malloc(sizeof(Tree));
		rt->x = x;
		rt->l = rt->r = NULL;
		return rt;
	}
	if(rt->x > x) {
		rt->l = Creat(rt->l, x);
	}else {
		rt->r = Creat(rt->r, x);
	}
	return rt;
}

bool flag;

void PreOrder(Tree *rt, int x){
	if(x == 1){
		printf("%d", rt->x);
		if(rt->l != NULL)
			PreOrder(rt->l,2);
		if(rt->r != NULL)
			PreOrder(rt->r,2);
	}else {
		printf(" %d", rt->x);
		if(rt->l != NULL)
			PreOrder(rt->l,2);
		if(rt->r != NULL)
			PreOrder(rt->r,2);
	}
}

void traverse(Tree* root) {
	if (root == NULL) {
		return;
	}
//	printf("%c%d", flag ? ' ' : '', root->x);
	flag = true;
	traverse(root->l);
	traverse(root->r);
}

int main(){
	freopen("3999.in", "r", stdin);
	freopen("3999.out", "w", stdout);
	int n, x;
	while(~scanf("%d", &n)){
		root = NULL;
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			root = Creat(root,x);
		}
		PreOrder(root,1);
		printf("\n");
	}
	return 0;
}
	

