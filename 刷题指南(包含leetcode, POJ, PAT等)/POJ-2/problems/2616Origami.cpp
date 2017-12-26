#include<math.h>
#include<stdio.h>
#define eps 1e-6
double sx1[10],sx2[10],sy1[10],sy2[10];
int ns;
int dfs(double x,double y,int s){
    double dist,dx,dy;
    if(s==0){
        if(x>eps && y>eps && x<100.0-eps && y<100.0-eps)
            return 1;
        return 0;
    }
    dx = sx2[s-1]-sx1[s-1],dy=sy2[s-1]-sy1[s-1];
    dist = sqrt(dx*dx+dy*dy);
    dx/=dist, dy/=dist;
    dist = dx*(y-sy1[s-1])-dy*(x-sx1[s-1]);
    if(dist<eps) return 0;
    return dfs(x,y,s-1)+dfs(x+2*dy*dist,y-2*dx*dist,s-1);
}
int main()
{
    int i,j,k,n;
    double x,y;
    scanf("%d",&ns);
    for(int i=0;i<ns;i++)
        scanf("%lf%lf%lf%lf",sx1+i,sy1+i,sx2+i,sy2+i);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&x,&y);
        printf("%d\n",dfs(x,y,ns));
    }
    return 0;
}
