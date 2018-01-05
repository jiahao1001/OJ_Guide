#include <iostream>  
using namespace std;  
__int64  Fac(int n){  
__int64  ans=1;  
for(int i=1;i<=n;i++)  
    ans=ans*i;  
return ans;  
}//nµÄ½×³Ë   
int main()  
{   freopen("2049.in", "r", stdin);
	freopen("2049.out", "w", stdout);
    int C;  
    cin>>C;  
    __int64 a[21];  
    a[1]=0;  
    a[2]=1;  
    for(int i=3;i<=20;i++)  
        a[i]=(a[i-2]+a[i-1])*(i-1);  
    while(C--){  
        int M,N;  
        cin>>M>>N;  
        cout<<Fac(M)/(Fac(M-N)*Fac(N))*a[N]<<endl;  
    }  
    return 0;  
}  
