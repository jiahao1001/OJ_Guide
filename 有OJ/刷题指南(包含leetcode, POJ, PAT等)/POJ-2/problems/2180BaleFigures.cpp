#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
int h[51][51][26];
//z, y , x
struct Point{
    int x,y,z;
}bale[25001];
int main(){
    int n,id,x,y,z,nx,ny,nz;
    char dir;
    int surface = 5;
    scanf("%d",&n);
    bale[1].z = 0, bale[1].x = 25, bale[1].y = 25;
    h[25][25][0] = 1;
    bool valid = true;
    for(int i=2;i<=n;i++){
        scanf("%d %c",&id,&dir);
        if(!valid) continue;
        bale[i].x = bale[id].x, bale[i].y = bale[id].y, bale[i].z = bale[id].z;
        if(dir=='L'){
            bale[i].x--;
        }else if(dir=='R'){
            bale[i].x++;
        }else if(dir=='F'){
            bale[i].y++;
        }else if(dir=='B'){
            bale[i].y--;
        }else if(dir=='O'){
            bale[i].z++;
        }else if(dir=='U'){
            bale[i].z--;
        }
        x = bale[i].x , y = bale[i].y, z = bale[i].z;
        if(h[x][y][z]) valid = false;
        else{
            h[x][y][z] = 1;
            surface += 6;
            if(z==0) surface --;
            if(z>0 && h[x][y][z-1]) surface-=2;
            if(z<25 && h[x][y][z+1]) surface-=2;
            if(x>0 && h[x-1][y][z]) surface-=2;
            if(x<50 && h[x+1][y][z]) surface-=2;
            if(y>0 && h[x][y-1][z]) surface-=2;
            if(y<50 && h[x][y+1][z]) surface-=2;
        }
        //printf("i = %d surface = %d\n",i,surface);
    }
    if(!valid) printf("-1\n");
    else printf("%d\n",surface);
    return 0;
}
