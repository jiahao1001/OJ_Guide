#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int n,sum;
int A[10];
int B[10][10];
bool reach(){
    for(int i=0;i<n;i++) B[0][i]=A[i];
    for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++) B[i][j] = B[i-1][j]+B[i-1][j+1];
    return B[n-1][0]==sum;
}

int main()
{
    scanf("%d%d",&n,&sum);
    for(int i=0;i<n;i++) A[i]=i+1;
    do{
        if(reach()) break;
    }while(next_permutation(A,A+n));
    printf("%d",A[0]);
    for(int i=1;i<n;i++) printf(" %d",A[i]);
    printf("\n");
    return 0;
}
