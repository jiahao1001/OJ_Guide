#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
char face[7][3][3];
struct Tup{
    int f,i,j;
    Tup(){}
    Tup(int _f,int _i,int _j):f(_f),i(_i),j(_j){}
};
Tup rot1[6][8]={
    {Tup(1,0,0),Tup(1,0,1),Tup(1,0,2),Tup(1,1,2),Tup(1,2,2),Tup(1,2,1),Tup(1,2,0),Tup(1,1,0)},
    {Tup(2,0,0),Tup(2,0,1),Tup(2,0,2),Tup(2,1,2),Tup(2,2,2),Tup(2,2,1),Tup(2,2,0),Tup(2,1,0)},
    {Tup(3,0,0),Tup(3,0,1),Tup(3,0,2),Tup(3,1,2),Tup(3,2,2),Tup(3,2,1),Tup(3,2,0),Tup(3,1,0)},
    {Tup(4,0,0),Tup(4,0,1),Tup(4,0,2),Tup(4,1,2),Tup(4,2,2),Tup(4,2,1),Tup(4,2,0),Tup(4,1,0)},
    {Tup(5,0,0),Tup(5,0,1),Tup(5,0,2),Tup(5,1,2),Tup(5,2,2),Tup(5,2,1),Tup(5,2,0),Tup(5,1,0)},
    {Tup(6,0,0),Tup(6,0,1),Tup(6,0,2),Tup(6,1,2),Tup(6,2,2),Tup(6,2,1),Tup(6,2,0),Tup(6,1,0)}
};
Tup rot2[6][12]={
    {Tup(5,0,0),Tup(5,1,0),Tup(5,2,0),Tup(2,0,0),Tup(2,1,0),Tup(2,2,0),Tup(6,0,0),Tup(6,1,0),Tup(6,2,0),Tup(4,2,2),Tup(4,1,2),Tup(4,0,2)},
    {Tup(5,2,0),Tup(5,2,1),Tup(5,2,2),Tup(3,0,0),Tup(3,1,0),Tup(3,2,0),Tup(6,0,2),Tup(6,0,1),Tup(6,0,0),Tup(1,2,2),Tup(1,1,2),Tup(1,0,2)},
    {Tup(5,2,2),Tup(5,1,2),Tup(5,0,2),Tup(4,0,0),Tup(4,1,0),Tup(4,2,0),Tup(6,2,2),Tup(6,1,2),Tup(6,0,2),Tup(2,2,2),Tup(2,1,2),Tup(2,0,2)},
    {Tup(5,0,2),Tup(5,0,1),Tup(5,0,0),Tup(1,0,0),Tup(1,1,0),Tup(1,2,0),Tup(6,2,0),Tup(6,2,1),Tup(6,2,2),Tup(3,2,2),Tup(3,1,2),Tup(3,0,2)},
    {Tup(4,0,2),Tup(4,0,1),Tup(4,0,0),Tup(3,0,2),Tup(3,0,1),Tup(3,0,0),Tup(2,0,2),Tup(2,0,1),Tup(2,0,0),Tup(1,0,2),Tup(1,0,1),Tup(1,0,0)},
    {Tup(2,2,0),Tup(2,2,1),Tup(2,2,2),Tup(3,2,0),Tup(3,2,1),Tup(3,2,2),Tup(4,2,0),Tup(4,2,1),Tup(4,2,2),Tup(1,2,0),Tup(1,2,1),Tup(1,2,2)}
};
char b1[8],b2[12];
void print(){
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++)printf(" ");
        for(int j=0;j<3;j++)printf(" %c",face[5][i][j]);
        printf("\n");
    }
    for(int i=0;i<3;i++)
        for(int k=1;k<=4;k++)
            for(int j=0;j<3;j++){
                printf("%c",face[k][i][j]);
                if(k==4 && j==2)printf("\n");
                else printf(" ");
            }
    
    
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++)printf(" ");
        for(int j=0;j<3;j++)printf(" %c",face[6][i][j]);
        printf("\n");
    }
}
void rotate(int x){
//    printf("rotate %d\n",x);
    
    bool lft;
    if(x<0) lft = true, x=-x;
    else lft = false;
    x--;
    for(int k=0;k<8;k++){
        int f = rot1[x][k].f;
        int i = rot1[x][k].i;
        int j = rot1[x][k].j;
        b1[k] = face[f][i][j];
    }
    for(int k=0;k<12;k++){
        int f = rot2[x][k].f;
        int i = rot2[x][k].i;
        int j = rot2[x][k].j;
        b2[k] = face[f][i][j];
    }
    if(lft){
        char a = b1[0],b=b1[1];
        char c;
        for(int i=2;i<8;i++)
            b1[i-2]=b1[i];
        b1[6]=a;
        b1[7]=b;
        a = b2[0],b=b2[1],c=b2[2];
        for(int i=3;i<12;i++)
            b2[i-3]=b2[i];
        b2[9] = a;
        b2[10]=b;
        b2[11] = c;
        
    }else{
        char a,b,c;
        a = b1[6],b=b1[7];
        for(int i=5;i>=0;i--)
            b1[i+2] = b1[i];
        b1[0] = a,b1[1] = b;
        a = b2[9],b=b2[10],c=b2[11];
        for(int i=8;i>=0;i--)
            b2[i+3] = b2[i];
        b2[0] = a, b2[1] = b, b2[2] = c;
        
    }
    
    for(int k=0;k<8;k++){
        int f =rot1[x][k].f;
        int i =rot1[x][k].i;
        int j =rot1[x][k].j;
        face[f][i][j] = b1[k];
    }
    for(int k=0;k<12;k++){
        int f =rot2[x][k].f;
        int i =rot2[x][k].i;
        int j =rot2[x][k].j;
        face[f][i][j]= b2[k];
    }
    
    
    
    
}
bool check(){
    for(int i=1;i<=6;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                if(face[i][j][k]!=face[i][0][0]) return false;
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    int q=1;
    while(t--){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                scanf(" %c",&face[5][i][j]);
        for(int i=0;i<3;i++){
            for(int k=1;k<=4;k++)
                for(int j=0;j<3;j++) scanf(" %c",&face[k][i][j]);
        }
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                scanf(" %c",&face[6][i][j]);
        int x,y;
        int cnt;
        scanf("%d",&cnt);
        for(int i=0;i<cnt;i++){
            scanf("%d%d",&x,&y);
            x++, x*=y;
            rotate(x);
        }
        printf("Scenario #%d:\n",q++);
        print();
        printf("\n");
        
    }
    return 0;
}
