#include<stdio.h>
#include<string.h>
int m,n,rear;
char sort[27];
bool letter[26][26],top[26],sorted;
int in_degree()
{
	int degree=-1,i,j;
	for (i=0;i<n;i++)
	{
		if (top[i]==true)
			continue;
		for (j=0;j<n;j++)
			if (letter[j][i]==true && top[j]==false)
				break;
		if (j==n)
		{
			if (degree==-1)
				degree=i;
			else {
				sorted=true;
				return degree;
			}
		}
	}
	return degree;
}
int main()
{
	int i,j,k;
	char str[10];
	bool f;
	while (scanf("%d%d",&n,&m),n!=0 || m!=0)
	{
		memset(letter,false,sizeof(letter));
		f=false;
		for (i=1;i<=m;i++)
		{
			scanf("%s",str);
			if (f==true)
				continue;
			letter[str[0]-'A'][str[2]-'A']=true;
			memset(top,false,sizeof(top));
			sorted=false;
			for (j=0;j<n;j++)
			{
				if ((k=in_degree())==-1)
				{
					printf("Inconsistency found after %d relations.\n",i);
					f=true;
					break;
				}
				top[k]=true;
				sort[j]=k+'A';
			}
			if (j==n && sorted==false)
			{
				sort[n]='\0';
				printf("Sorted sequence determined after %d relations: %s.\n",i,sort);
				f=true;
			}
		}
		if (f==false)
			printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}
