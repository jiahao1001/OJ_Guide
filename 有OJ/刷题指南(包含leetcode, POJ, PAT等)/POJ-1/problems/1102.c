#include<stdio.h>
int main()
{
	int n,i,j,k;
	char s[9],c[3][10]={{'-',' ','-','-',' ','-','-','-','-','-'},
	{' ',' ','-','-','-','-','-',' ','-','-'},{'-',' ','-','-',' ','-','-',' ','-','-'}};
	char l[2][10][2]={{'|','|',' ','|',' ','|',' ','|','|','|','|',' ','|',' ',' ','|','|','|','|','|'},
	{'|','|',' ','|','|',' ',' ','|',' ','|',' ','|','|','|',' ','|','|','|',' ','|'}};
	scanf("%d %s",&n,s);
	while (n!=0 || s[0]!='0')
	{
		for (i=0;s[i]!='\0';i++)
		{
			printf(" ");
			for (j=0;j<n;j++)
				printf("%c",c[0][s[i]-'0']);
			printf("  ");
		}
		printf("\n");
		for (j=0;j<n;j++)
		{
			for (i=0;s[i]!='\0';i++)
			{
				printf("%c",l[0][s[i]-'0'][0]);
				for (k=0;k<n;k++)
					printf(" ");
				printf("%c ",l[0][s[i]-'0'][1]);
			}
			printf("\n");
		}
		for (i=0;s[i]!='\0';i++)
		{
			printf(" ");
			for (j=0;j<n;j++)
				printf("%c",c[1][s[i]-'0']);
			printf("  ");
		}
		printf("\n");
		for (j=0;j<n;j++)
		{
			for (i=0;s[i]!='\0';i++)
			{
				printf("%c",l[1][s[i]-'0'][0]);
				for (k=0;k<n;k++)
					printf(" ");
				printf("%c ",l[1][s[i]-'0'][1]);
			}
			printf("\n");
		}
		for (i=0;s[i]!='\0';i++)
		{
			printf(" ");
			for (j=0;j<n;j++)
				printf("%c",c[2][s[i]-'0']);
			printf("  ");
		}
		printf("\n\n");
		scanf("%d %s",&n,s);
	}
	return 0;
}
