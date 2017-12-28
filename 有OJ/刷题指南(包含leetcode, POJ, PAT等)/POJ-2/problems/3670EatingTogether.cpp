#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
#include<float.h>
#include<math.h>
using namespace std;
const int N = 30000;
int n;
int A1[N],A2[N];
int B[N];
int LIS(int A[]){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int j = upper_bound(B,B+cnt,A[i])-B;
        if(j==cnt) B[cnt++]=A[i];
        else B[j] = A[i];
    }
    //for(int i=0;i<cnt;i++)
      //  cout<<B[i]<<" ";
    //cout<<endl;
    return cnt;
}
int main()
{
    scanf("%d",&n);
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        A1[i] = A2[n-i-1] = x;
    }
    printf("%d\n",min(n-LIS(A1),n-LIS(A2)));
    return 0;
}
