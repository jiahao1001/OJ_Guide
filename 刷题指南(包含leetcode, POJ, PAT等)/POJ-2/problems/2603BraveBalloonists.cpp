#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int,int> PII;
int A[10];
vector<PII> factors[10];
int main()
{
    int n=10;
    for(int i=0;i<10;i++) scanf("%d",A+i);
    for(int i=0;i<n;i++){
        while(A[i]!=1){
            int j;
            for(j=2;j<=A[i];j++){
                if(A[i]%j==0) break;
            }
            int cnt=0;
            while(A[i]%j==0) cnt++,A[i]/=j;
            if(cnt==0) break;
            factors[i].push_back(make_pair(j,cnt));
        }
    }
    priority_queue<PII> heap;
    for(int i=0;i<n;i++)
        for(int j=0;j<factors[i].size();j++) heap.push(factors[i][j]);
    int p = 1;
    int cnt = 0;
    int last = -1;
    while(!heap.empty()) {
        PII head = heap.top();
        int fac  = head.first, c = head.second;
        if(fac!=last){
            p = (p*(cnt+1))%10;
            cnt = c;
            last = fac;
        }else cnt+=c;
        
        heap.pop();
    }
    p = (p*(cnt+1))%10;
    printf("%d\n",p);
    return 0;
}
