#include<iostream>
#include<stdio.h>
using namespace std;
double rate[100][100];
double commission[100][100];
double money[100];
int n,M,S;
double V;
int main()
{
    int a,b;
    double rab,cab,rba,cba;
    scanf("%d%d%d%lf",&n,&M,&S,&V);
    S--;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%lf%lf%lf%lf",&a,&b,&rab,&cab,&rba,&cba);
        a--,b--;
        rate[a][b]=rab;
        rate[b][a]=rba;
        commission[a][b]=cab;
        commission[b][a]=cba;
    }
    money[S]=V;
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(rate[i][j]!=0 && money[i]>commission[i][j]) money[j]=max(money[j],rate[i][j]*(money[i]-commission[i][j]));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(rate[i][j]*(money[i]-commission[i][j])>money[j]){
                printf("YES\n");
                return 0;
            }
    printf("NO\n");
    return 0;
}
