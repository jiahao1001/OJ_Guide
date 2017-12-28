#include <iostream>
using namespace std;
/*inline int sc(int* &data,int &x,int l,int r)
{
    if (data[l]>x) return l;
    if (data[r]<=x) return r+1;
    int mid;
    while (l+8<r)
    {
        mid=(l+r)/2;
        if ((data[mid]>x)&&(data[mid-1]<=x)) return mid;
        if (data[mid]<=x)
        {
            l=mid+1;
            if (data[l]>x) return l;
        } else r=mid-1;
    }
    while (data[l]<=x) ++l;
    return l;
}*/
int main()
{
    int n,t,i,x,l,r,mid,res;unsigned long long *data,*p;
    cin>>n>>t;
    data=new unsigned long long[n+1];
    data[0]=0;
    for (i=1;i<=n;++i) cin>>data[i];
    p=new unsigned long long[t];
    for (i=0;i<t;++i) cin>>p[i];
    for (i=0;i<t;++i)
    {
        l=1;
        r=n;
        while (1)
        {
            if (data[l]>p[i])
            {
                res=l;
                break;
            }
            if (data[r]<=p[i])
            {
                res=r+1;
                break;
            }
            if (l+8<r)
            {
                while (data[l]<=p[i]) ++l;
                res=l;
                break;
            }
            mid=(l+r)/2;
            if (data[mid]<=p[i]) l=mid+1;
            else r=mid-1;
        }
        cout<<n-res+1<<endl;
    }
    delete [] data;
    delete [] p;
}
/*
#include<iostream>
using namespace std;
int main()
{
	int N, T, i, result;
	unsigned int num;
	cin >> N >> T;
	int gap, trial;
	unsigned int * const NN = new unsigned int[N];
	unsigned int * const TT = new unsigned int[T];
	for (i = 0; i < N; ++i)cin >> NN[i];
	for (i = 0; i < T; ++i)cin >> TT[i];
	for (i = 0; i < T; ++i)
	{
		trial = N / 2;
		gap = N / 4;
		num = TT[i];
		for (;;)
		{
			if (trial < 0)
			{
				result = -1;
				break;
			}
			if (trial >= N)
			{
				result = N - 1;
				break;
			}
			if (trial < N - 1 && NN[trial]<num && NN[trial + 1]>num)
			{
				result = trial;
				break;
			}
			if (NN[trial] == num)
			{
				result = trial;
				break;
			}
			else if (NN[trial] > num)trial -= gap;
			else trial += gap;
			if (gap != 1)gap /= 2;
		}
		cout << (N - 1 - result) << '\n';
	}
	//system("pause");
	return 0;
}
*/
