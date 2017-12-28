#include <cstdio>
int main()
{
    int stack[1000];
    int size=0,i,n,op,num;
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf("%d %d",&op,&num);
        if (op==1)
        {
            stack[size++]=num;
            printf("OK\n");
        }
        else
        {
            if (size==0) printf("ERROR\n");
            else
            {
                if (stack[size-1]==num) printf("YES\n");else printf("NO\n");
                --size;
            }
        }
    }
}
