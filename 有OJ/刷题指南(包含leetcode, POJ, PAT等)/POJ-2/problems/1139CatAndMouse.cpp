#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int N = 101;
int n,cat, mouse;
int cat_door[N][N];
int mouse_door[N][N];
int cat_room[N],mouse_room[N];
void dfs(int i,int* rooms,int doors[][N]){
    for(int j=1;j<=n;j++)
        if(doors[i][j] && !rooms[j]){
            rooms[j] = 1;
            dfs(j,rooms,doors);
        }
}
int safe[N];
void dfs_safe(int i){
    for(int j=1;j<=n;j++)
        if(!cat_room[j] && mouse_door[i][j] && !safe[j]){
            safe[j] = 1;
            dfs_safe(j);
        }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(cat_door,0,sizeof cat_door);
        memset(mouse_door,0,sizeof mouse_door);
        memset(cat_room,0,sizeof(cat_room));
        memset(mouse_room,0,sizeof mouse_room);
        scanf("%d%d%d",&n,&cat,&mouse);
        int a,b;
        while(scanf("%d%d",&a,&b),a!=-1 && b!=-1){
            cat_door[a][b] = 1;
        }
        
        while(scanf("%d%d",&a,&b),a!=-1 && b!=-1){
            mouse_door[a][b] = 1;
        }
        cat_room[cat] = 1;
        mouse_room[mouse] = 1;
        dfs(cat,cat_room,cat_door);
        dfs(mouse,mouse_room,mouse_door);
        bool met = false;
        bool isSafe = false;
        for(int i=1;i<=n;i++)
            if(cat_room[i] && mouse_room[i]) met = true;
        if(cat==mouse) isSafe = false;
        else{
            //all reachable room without any cat room
            memset(safe,0,sizeof safe);
            safe[mouse] = 1;
            dfs_safe(mouse);
            for(int i=1;i<=n;i++)
                if(i!=mouse && safe[i] && mouse_door[i][mouse]) isSafe = true;
        }
        printf("%c %c\n",met?'Y':'N',isSafe?'Y':'N');
    }
    return 0;
}
