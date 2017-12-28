#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<utility>
using namespace std;
typedef pair<int,int> PII;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
char line[60];
char maze[60][60];
int visited[60][60];
int mirror(char *s){
    return isdigit(s[0]);
}
int wall(char *s){
    return s[1]=='#' || s[1]==' ' || s[1] == '-';
}
PII mirrors[10];
int n,m;
PII get_mirror(char *s){
    if(!strcmp(s,"-/"))
        return make_pair(1,2);
    else if(!strcmp(s,"-\\"))
        return make_pair(0,1);
    else if(!strcmp(s,"/-"))
        return make_pair(0,3);
    else return make_pair(2,3);
}
bool hit_wall(int i,int j){
    return i<=0 || i>=n-1 || j<=0 || j>=m-1;
}
PII path[20]; //mirror cannot block the path

inline bool between(int a,int b,int c){
    if(b>c) swap(b,c);
    return b<a && a<c;
}
void dfs(int i,int j,int dir,int mask,int cnt){
    //printf("try (%d %d) dir = %d\n",i,j,dir);
    
    //go ahead until hit a mirror or the wall
    int k=1,x,y;
    while(true){
        x=i+k*dx[dir], y=j+k*dy[dir];
        if(hit_wall(x,y) || isdigit(maze[x][y])) break;
        k++;
    }
    //x,y is the new point
    if(hit_wall(x,y)){
        //printf("hits %d %d\n",x,y);        
        visited[x][y] = 1;
        return;
    }
    
    //not using mirror
    dfs(x,y,dir,mask,cnt);
    
    //x,y is a mirror
    int id = maze[x][y]-'0';
    if((mask&(1<<id))!=0) return;//mirror alreay used
    if(mirrors[id].first==-1) return; //not a valid mirror
    if(mirrors[id].first!=(dir+2)%4 && mirrors[id].second!=(dir+2)%4) return;//miror blocking ray
    //check if mirror in the path
    for(int i=1;i<cnt;i++){
        PII &p1 = path[i-1];
        PII &p2 = path[i];
        if(p1.first==p2.first && p1.first == x && between(y,p1.second,p2.second)) return;
        if(p1.second==p2.second && p1.second == y && between(x,p1.first,p2.first)) return;
    }
    path[cnt] = make_pair(x,y);
    if((dir+2)%4 == mirrors[id].first) dir = mirrors[id].second;
    else dir = mirrors[id].first;
    dfs(x,y,dir,(mask|(1<<id)),cnt+1);
}
int main()
{
    int t;
    scanf("%d",&t);
    gets(line);
    while(t--){
        for(int i=0;i<10;i++) mirrors[i] = make_pair(-1,-1);
        while(true){
            gets(line);
            if(!mirror(line)) break;
            mirrors[line[0]-'0'] = get_mirror(line+2); 
        }
        m = strlen(line);
        for(int i=0;i<m;i++) maze[0][i] = line[i];
        maze[0][m] = '\0';
        n = 1;
        do{
            gets(maze[n++]);
        }while(!wall(maze[n-1]));
        //for(int i=0;i<10;i++)
            //printf("mirror %d -> %d %d\n",i,mirrors[i].first,mirrors[i].second);
        
        //get the start point of the ray
        PII start;
        int dir;
        for(int i=0;i<n;i++)
            if(maze[i][0]==' ') start.first = i, start.second = 0, dir = 1;
            else if(maze[i][m-1]==' ') start.first = i, start.second = m-1, dir = 3;
        for(int j=0;j<m;j++)
            if(maze[0][j]==' ') start.first = 0, start.second = j, dir = 2;
            else if(maze[n-1][j]==' ') start.first = n-1, start.second = j, dir = 0;
        
        memset(visited,0,sizeof(visited));
        path[0] = start;
        dfs(start.first,start.second,dir,0,1);
        bool ok = true;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((maze[i][j]=='-'||maze[i][j]=='|') && !visited[i][j]) ok = false;
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
