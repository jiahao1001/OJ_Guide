#include<stdio.h>
#include<math.h>
int n,d,r,s,t,i;
double min;
int main()
{
    scanf("%d%d",&n,&d);
    min=32767;
    for(i=1;i<=32767;i++)
    {
        r=floor(i*1.0*n/d+0.5);
        if(r*d==n*i)
        {
            if(fabs((r+1)*1.0/i-n*1.0/d)>fabs((r-1)*1.0/i-n*1.0/d)) 
				r++;
            else r--;
        }
        if(fabs(r*1.0/i-n*1.0/d)<min)
        {
            min=fabs(r*1.0/i-n*1.0/d);
            t=r;
            s=i;
        }
    }
    printf("%d %d\n",t,s);
	return 0;
}
