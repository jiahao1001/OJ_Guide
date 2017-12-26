#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int X,Y;
char paper[100][100];
void draw_pixel(int i,int j,char c){
    if(paper[i][j]==' ' || paper[i][j]==c){
        paper[i][j] = c;
        return;
    }
    char o = paper[i][j];
    if(o=='+' && (c=='|'||c=='-')) return;
    if(o=='|' && c=='-') paper[i][j]='+';
    else if(o=='-' && c=='|') paper[i][j]='+';
    else if(o=='\\' && c=='/') paper[i][j] = 'x';
    else if(o=='/' && c=='\\') paper[i][j] = 'x';
    else paper[i][j]='*';
    
}
void draw_frame(int w,int h){
    memset(paper,' ',sizeof paper);
    for(int i=0;i<=h+1;i++) paper[i][w+2] = '\0';
    for(int i=0;i<=w+1;i++)
        draw_pixel(0,i,'-'), draw_pixel(h+1,i,'-');
    for(int i=0;i<=h+1;i++)
        draw_pixel(i,0,'|'), draw_pixel(i,w+1,'|');
}
void draw_point(int x,int y){
    draw_pixel(y,x,'o');
}
void draw_line(int x1,int y1,int x2,int y2){
    // ----> x
    if(y1==y2){
        if(x1>x2) swap(x1,x2);
        for(int j=x1;j<=x2;j++)
            draw_pixel(y1,j,'-');
        return;
    }
    if(y1>y2) swap(y1,y2),swap(x1,x2);
    if(x1==x2){
        if(y1>y2) swap(y1,y2);
        for(int i=y1;i<=y2;i++)
            draw_pixel(i,x1,'|');
    }else if(x1<x2){
        for(int i=y1;i<=y2;i++)
            draw_pixel(i,x1+i-y1,'\\');
    }else {
        for(int i=y1;i<=y2;i++)
            draw_pixel(i,x1-i+y1,'/');
    }
}
void draw_text(int x,int y,string txt){
    for(int k=0;k<txt.size() && x+k<X+1;k++)
        draw_pixel(y,x+k,txt[k]);
}
void clear(int x1,int y1,int x2,int y2){
    if(x1>x2) swap(x1,x2);
    if(y1>y2) swap(y1,y2);
    for(int i=y1;i<=y2;i++)
        for(int j=x1;j<=x2;j++)
            paper[i][j] = ' ';
}
int main()
{
    while(cin>>X>>Y){
        if(!X && !Y) break;
        //draw frame
        draw_frame(X,Y);
        string cmd,txt;
        int x1,y1,x2,y2;
        while(cin>>cmd,cmd!="PRINT"){
            if(cmd=="LINE"){
                cin>>x1>>y1>>x2>>y2;
                draw_line(x1,y1,x2,y2);
            }else if(cmd=="POINT"){
                cin>>x1>>y1;
                draw_point(x1,y1);
            }else if(cmd=="CLEAR"){
                cin>>x1>>y1>>x2>>y2;
                clear(x1,y1,x2,y2);
            }else if(cmd=="TEXT"){
                cin>>x1>>y1>>txt;
                draw_text(x1,y1,txt);
            }
        }
        for(int i=0;i<=Y+1;i++)
            cout<<paper[i]<<endl;
        cout<<endl;
    }
    return 0;
}
