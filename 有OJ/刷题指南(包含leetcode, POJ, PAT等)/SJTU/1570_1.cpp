#include<iostream>
using namespace std;
int main()
{
	int n,t,i,x,tr,itv,res;
    cin>>n>>t;
	unsigned r,*data=new unsigned[n],*p=new unsigned[t];
    data[0]=0;
    for (i=0;i<n;++i) cin>>data[i];
    for (i=0;i<t;++i) cin>>p[i];
	for (i=0;i<t;++i)
	{
	    r=p[i];
		tr=n/2;
		itv=n/4;
		while (1)
		{
			if (tr<0)
			{
				res=-1;
				break;
			}
			else if (tr>=n)
			{
				res=n-1;
				break;
			}
			else if (tr<n-1&&data[tr]<r&&data[tr+1]>r)
			{
				res=tr;
				break;
			}
			else if (data[tr]==r)
			{
				res=tr;
				break;
			}
			else if (data[tr]>r) tr-=itv;
			else tr+=itv;
			if (itv!=1) itv/= 2;
		}
		cout<<(n-1-res)<<'\n';
	}
	return 0;
}
