#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<cstdlib>
using namespace std;
int A[1002], B[1002];

struct Tree{
	Tree *l, *r;
	int x;
}tree;

Tree *PreInCreat(int A[], int B[], int l1, int h1, int l2, int h2){
	int llen, rlen, i;
	Tree *root;
	root = (Tree*)malloc(sizeof(Tree));
	root->x = A[l1];
	for(i = l2; B[i]!=root->x; i++);
	llen = i - l2;
	rlen = h2 - i;
	if(llen)
		root->l = PreInCreat(A, B, l1+1, l1+llen, l2, l2+llen-1);
	else
		root->l = NULL;
	if(rlen)
		root->r = PreInCreat(A, B, h1-rlen+1, h1, h2-rlen+1, h2);
	else
		root->r = NULL;
	return root;
}
bool flag;
int PostOrder(Tree *T){
	if(T!=NULL){
		PostOrder(T->l);
		PostOrder(T->r);
		if(flag){
			printf(" %d",T->x);
		}else{
			printf("%d", T->x);
		}
		flag = true;
	}
		return 0;
}

int main(){
	freopen("1710.in", "r", stdin);
	freopen("1710.out", "w", stdout);
	int n, i;
	Tree *root;
	while(~scanf("%d", &n)){
	
		for(i=0; i < n; i++)
		scanf("%d", &A[i]);
		for(i=0; i<n; i++)
		scanf("%d",&B[i]);
		root = PreInCreat(A, B, 0, n-1, 0, n-1);
		flag = false;
		PostOrder(root);
		printf("n");		
	}
}
