#include <stdio.h>
#include <string.h>

int main()
{
    char a[110],b[110],c[110],code[30];
    int i,j,n;
    bool flag=false;
    memset(code,0,sizeof(code));

    scanf("%s\n%s\n%s",a,b,c);

    n=strlen(a);

    for(i=0;i<n;i++)
    {
        if(code[a[i]-'A']==0)code[a[i]-'A']=b[i];
        else if(b[i]!=code[a[i]-'A'])
        {
            flag=true;
            break;
        }
    }

    if(flag)
    {
        printf("Failed");
        return 0;
    }

    for(i=0;i<26;i++)
        if(code[i]==0)
        {
            printf("Failed");
            return 0;
        }

    for(i=0;i<25;i++)
        for(j=i+1;j<26;j++)
        {
            if(code[i]==code[j])
            {
                printf("Failed");
                return 0;
            }
        }

    
    n=strlen(c);
    for(i=0;i<n;i++)
    {
        printf("%c",code[c[i]-'A']);
    }
    


    return 0;
}