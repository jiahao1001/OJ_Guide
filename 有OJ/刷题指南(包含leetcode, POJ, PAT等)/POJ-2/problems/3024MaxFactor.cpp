#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 5000;
int n;
int A[N],B[N];
int C[N];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",A+i);
        B[i] = A[i];
    }
    
    for(int i=0;i<n;i++){
        C[i] = 0;
        int j=2;
        for(j=2;;j++){
            while(B[i]%j==0){
                C[i] = j;
                B[i]/=j;
            }
            if(B[i]==1) break;
        }
    }
    int best=-1, id;
    for(int i=0;i<n;i++){
        if(C[i]>best) best = C[i],id=i;
    }
    printf("%d\n",A[id]);
    
    return 0;
}
