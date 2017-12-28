#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
#include<string>
#include<map>
using namespace std;
const int N = 310;
const int M = 310;
bool DEBUG = false;
map<string,int> day;
int n,m;
int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int k,t;
char s1[10],s2[10];
int A[N][M];
int x[M];
//m unknown
//3 days to 9 days
void print(){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m+1;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
}

inline void eliminate(int row,int i,int col){
    //pivot is A[row][col]
    int p = A[row][col];
    int q = A[i][col];
    int g = lcm(p,q);
    for(int j=1;j<=m+1;j++){
        A[i][j] = (A[i][j]*g/q-A[row][j]*g/p)%7;;
        if(A[i][j]<0) A[i][j] += 7;
    }
}
int guass(){
    if(DEBUG) print();
    int col = 1;
    int row = 1;
    while(col<=m && row<=n){
        int id = row;
        for(id=row;id<=n;id++)
            if(A[id][col]) break;
        if(id==n+1){
            //free variable
            col++;
            continue;
        }
        for(int j=1;j<=m+1;j++) swap(A[row][j],A[id][j]);//swap to row
        for(int i=1;i<=n;i++)
            if(i!=row && A[i][col]!=0) eliminate(row,i,col);
        col++, row++;
    }
    if(DEBUG) print();
    int rank = row-1;
    for(;row<=n;row++)
        if(A[row][m+1]) return -1;
    if(rank<m) return -2;
    //get the x
    for(int i=1;i<=m;i++){
        for(int d = 3;d<=9;d++)
            if((A[i][i]*d) % 7 == A[i][m+1]) x[i] = d;
    }
    return 0;
}
int main(){
    day["MON"] = 0;
    day["TUE"] = 1;
    day["WED"] = 2;
    day["THU"] = 3;
    day["FRI"] = 4;
    day["SAT"] = 5;
    day["SUN"] = 6;
    while(scanf("%d%d",&m,&n),n||m){
        memset(A,0,sizeof(A));
        for(int i=1;i<=n;i++){
            scanf("%d%s%s",&k,s1,s2);
            int d1 = day[string(s1)], d2 = day[string(s2)];
            int d = ((d2-d1)+7)%7 + 1;
            A[i][m+1] = d;
            for(int j=0;j<k;j++){
                scanf("%d",&t);
                A[i][t]++;
            }
            for(int j=1;j<=m+1;j++) A[i][j] %= 7;
        }
        int r = guass();
        if(r==-1) printf("Inconsistent data.\n");
        else if(r==-2) printf("Multiple solutions.\n");
        else{
            printf("%d",x[1]);
            for(int i=2;i<=m;i++)
                printf(" %d",x[i]);
            printf("\n");
        }
        
    }
    
    return 0;
}
