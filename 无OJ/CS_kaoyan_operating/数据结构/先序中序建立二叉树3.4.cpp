#include<stdio.h>
#include<string.h>
struct Node
{
	Node *lchild;
	Node *rchild;
	char c;
}Tree[50];
int loc;
char str1[30],str2[30];
Node *create()
{
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}
Node *build(int s1,int e1,int s2,int e2)
{ //先序起止，中序起止
	Node *ret = create();
	ret->c = str1[s1];
	int rootIdx;
	for(int i=s2;i<=e2;i++)
		//对str2[]进行搜索,要注意
		if(str2[i]==ret->c)
		{
			rootIdx = i;
			break;
		}
	if(rootIdx!=s2)
		//有左子树
		ret->lchild = build(s1+1,s1+(rootIdx-s2),s2,rootIdx-1);
	if(rootIdx!=e2)
		ret->rchild = build(s1+(rootIdx-s2)+1,e1,rootIdx+1,e2);
	return ret;
}
void postOrder(Node *T)
{
	if(T->lchild!=NULL)
		postOrder(T->lchild);
	if(T->rchild!=NULL)
		postOrder(T->rchild);
	printf("%c",T->c);
}
int main()
{
	loc = 0; //初始化
	while(scanf("%s",str1)!=EOF)
	{
		scanf("%s",str2);
		int L1 = strlen(str1);
		int L2 = strlen(str2);
		Node *T = build(0,L1-1,0,L2-1);
		postOrder(T);
		printf("\n");
	}
	return 0;
}