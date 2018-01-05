#include<stdio.h>
#include<string.h>
struct Node
{
	Node *lchild;
	Node *rchild;
	int c;
}Tree[110];
char str1[25],str2[25];
int loc;
int *size; char *str;
int size1,size2;
Node *create()
{
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}
void postOrder(Node *T)
{ //后序遍历
	if(T->lchild!=NULL)
		postOrder(T->lchild);
	if(T->rchild!=NULL)
		postOrder(T->rchild);
	str[(*size)++] = T->c + '0'; 
	//将数字变为字符存起来
}
void inOrder(Node *T)
{ //中序遍历
	if(T->lchild!=NULL)
		inOrder(T->lchild);
	
	str[(*size)++] = T->c + '0'; 

	if(T->rchild!=NULL)
		inOrder(T->rchild);	
}
Node *Insert(Node *T,int x)
{
	if(T == NULL)
	{ //要调用create()函数
		T = create();
		T->c = x;
		return T;
	}
	else if(x < T->c)
		T->lchild = Insert(T->lchild,x);
	else if(x > T->c)
		T->rchild = Insert(T->rchild,x);
	return T;
	//因为这个函数是Node型的，所以最后要返回T
}
int main()
{
	char tmp[12];
	int n;
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",tmp);
		loc = 0;//初始化静态空间
		Node *T = NULL;
		for(i=0;tmp[i]!='\0';i++)
			T = Insert(T,tmp[i]-'0');
		size1 = 0;
		//初始化,最后相当于把后续和中序遍历的放在一个字符串中
		size = &size1;
		str = str1;
		postOrder(T);
		inOrder(T);
		str1[size1] = '\0';
		while(n--!=0)
		{
			scanf("%s",tmp);
			Node *T2 = NULL;
			for(i=0;tmp[i]!='\0';i++)
				T2 = Insert(T2,tmp[i]-'0');
			size2 = 0; //初始化
			size = &size2;
			str = str2;
			postOrder(T2);
			inOrder(T2);
			str2[size2] = '\0';
			puts(strcmp(str1,str2)==0?"YES":"NO");
		}
	}
	return 0;
}