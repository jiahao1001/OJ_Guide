#include <stdio.h>
#include <string.h>
#define CHK(x,y) ((x)>=0 && (y)>=0 && (x)<w && (y)<h && map[y][x]!='#')

char map[100][101];
int m[200][100][100];

int main(void)
{
    int N,w,h,x1,y1,x2,y2,dx1,dx2,step,best,v;
    
    scanf("%d",&N);
    while (N--) {
        scanf("%d %d",&w,&h);
        for(y1=0;y1<h;y1++) {
            scanf("%s",map[y1]);
            
        }
        memset(m,-1,sizeof m);
        m[0][0][0]=map[0][0]=='*';
        for(step=1;step<w+h-1;step++)
            for(x1=0;x1<=step;x1++)
                for(x2=x1;x2<=step;x2++) {
                    y1=step-x1;
                    y2=step-x2;
                    best=-1;
                    if (!CHK(x1,y1) || !CHK(x2,y2)) continue;
                    for(dx1=0;dx1<2;dx1++)
                        for(dx2=0;dx2<2;dx2++)
                            if (CHK(x1-dx1,y1-!dx1) && CHK(x2-dx2,y2-!dx2)) {
                                v=m[step-1][x1-dx1][x2-dx2];
                                if(v==-1)continue;
                                if (v>best) best=v;
                            }
                    v=(map[y1][x1]=='*')+(map[y2][x2]=='*');
                    if (v==2 && x1==x2) v=1;
                    m[step][x1][x2]=best+v;
                }
        
        printf("%d\n",m[w+h-2][w-1][w-1]);
    }
    return 0;
}
