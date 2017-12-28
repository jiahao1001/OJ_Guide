#include<iostream>
#include<stdio.h>
#include<string.h>
#define MOD 3209
using namespace std;

struct Snow{
    int len[6];
};
struct Item
{
    Snow snow;
    int next;
} items[100000];
int cnt;
int bucket[MOD];
int n,len;
Snow snow;
int compare(Snow &s1, Snow &s2)
{
    for(int i=0;i<6;i++)
    {
        int j=0;
        for(j=0;j<6;j++)
            if(s2.len[j]!=s1.len[(i+j)%6]) break;
        if(j==6) return 1;
    }
    for(int i=0;i<6;i++)
    {
        int j=0;
        for(j=0;j<6;j++)
            if(s2.len[j]!=s1.len[(i+6-j)%6]) break;
        if(j==6) return 1;
    }
    return 0;
    
}
int found(Snow &snow,int h)
{
    int i;
    for(i=bucket[h];i!=-1;i=items[i].next){
        if(compare(snow,items[i].snow)) return 1;
    }
    //insert to hash table
    items[cnt].snow=snow;
    items[cnt].next=bucket[h];
    bucket[h]=cnt;
    cnt++;
    return 0;
}
int data[100000][6];
int main()
{
    memset(bucket,-1,sizeof(bucket));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<6;j++)
            scanf("%d",&data[i][j]);
    for(int i=0;i<n;i++)
    {
        int h=0;
        for(int j=0;j<6;j++){
            len = data[i][j];
            snow.len[j]=len;
            h+=len;
            h%=MOD;
        }
        if(found(snow,h)){
            printf("Twin snowflakes found.\n");
            return 0;
        }
    }
    printf("No two snowflakes are alike.\n");
    return 0;
}
