#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
int h3[13],h4[13];
int main()
{
    h3[1] = h4[1] = 1;
    for(int i=2;i<=12;i++)
        h3[i] = 2*h3[i-1]+1;
    for(int i=2;i<=12;i++){
        h4[i] = 2+h3[i-1];
        for(int j=2;j<i;j++) h4[i] = min(h4[i],2*h4[j]+h3[i-j]);
    }
    for(int i=1;i<=12;i++) printf("%d\n",h4[i]);
    return 0;
}
