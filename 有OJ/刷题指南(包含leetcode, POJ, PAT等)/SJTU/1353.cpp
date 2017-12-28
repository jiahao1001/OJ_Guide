#include <stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    while (x!=0)
    {
        if (x<=100) printf("91\n");
        else printf("%d\n",x-10);
        scanf("%d",&x);
    }
}
