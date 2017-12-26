#include <stdio.h>
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d%d",&a,&b);
        printf("%s BRAINS\n",(a<b?"NO":"MMM"));
    }    
	return 0;
}
