# include<stdio.h>
# include<string.h>
int main()
{freopen("2024.in", "r", stdin);
    freopen("2024.out", "w", stdout);
    int n,i,j;
    char s[51];
  
    scanf("%d",&n);
    getchar( );
    for(i=0; i<n; i++)
    {
        int flag=1;
        gets(s);
        for(j=0; s[j]!='\0'; j++)
        {
            if(!((s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')||(s[j]=='_')))
            {
                flag=0;
            }
        }
        if(s[0]>='0'&&s[0]<='9')flag=0;
        if(flag)  printf("yes\n");
        else  printf("no\n");
      
    }
    return 0;
}
