#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
int leap(int y){
    return (y%400==0 || ((y%100)&&(y%4==0)))?1:0;
}
//1800 1 1 is the day 1

int mm[2][12]={
    {0,31,28,31,30,31,30,31,31,30,31,30},
    {0,31,29,31,30,31,30,31,31,30,31,30}};

int day(int y,int m,int d){
    int days = 0;
    for(int i=1800;i<y;i++)
        days+=365+leap(i);
    for(int i=0;i<m;i++)
        days+=mm[leap(y)][i];
    return days+d;
}
char p[7][20]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main(){
    int y,m,d;
    int d1 = day(1900,1,1);
    scanf("%d%d%d",&y,&m,&d);
    int d2 = day(y,m,d);
    int i = (d2-d1)%7;
    if(i<0) i+=7;
    printf("%s\n",p[i]);
    return 0;
}
