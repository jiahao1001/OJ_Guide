#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
  
using namespace std;  
  
const int maxn=110000;  
  
int n,m,q;  
int a[maxn],t[maxn];  
int tot,T[maxn],lson[maxn*30],rson[maxn*30],c[maxn*30];  
  
void hash_init()  
{  
    sort(t+1,t+1+n);  
    m=unique(t+1,t+1+n)-t;    
}  
  
int hash(int x)  
{  
    return lower_bound(t+1,t+1+m,x)-t;  
}

int build(int l,int r){
    int root = tot++,temp = root;
    c[root] = 0;
    if(l!=r){
        int mid = (l+r)>>1;
        lson[root] = build(l,mid);
        rson[root] = build(mid+1,r);
    }
    return temp;
}
int update(int root,int pos,int val){
    int newroot = tot++, temp = newroot;
    c[newroot] = c[root]+val;
    int l=1,r=m;
    while(l<r){
        int mid = (l+r)>>1;
        if(pos<=mid){
            lson[newroot] = tot++, rson[newroot] = rson[root];
            root = lson[root], newroot = lson[newroot];
            r = mid;
        }else{
            rson[newroot] = tot++, lson[newroot] = lson[root];
            root = rson[root], newroot = rson[newroot];
            l=mid+1;
        }
        c[newroot] = c[root]+val;
    }
    
    return temp;
}
int query(int left_root, int right_root, int x){
    int l=1,r=m;
    while(l<r){
        int mid = (l+r)>>1;
        int tt = c[lson[left_root]]-c[lson[right_root]];
        if(tt>=x){
            left_root = lson[left_root];
            right_root = lson[right_root];
            r = mid;
        }
        else{
            x-=tt;
            left_root = rson[left_root];
            right_root = rson[right_root];
            l = mid+1;
        }
    }
    return l;
}


int main()  
{  
    while(scanf("%d%d",&n,&q)!=EOF)  
    {  
        memset(c,0,sizeof(c)); tot=0;  
        for(int i=1;i<=n;i++)      
        {  
            scanf("%d",a+i);  
            t[i]=a[i];  
        }  
        hash_init();  
        T[n+1]=build(1,m);  
        for(int i=n;i;i--)  
        {  
            T[i]=update(T[i+1],hash(a[i]),1);  
        }  
        while(q--)  
        {  
            int a,b,c;  
            scanf("%d%d%d",&a,&b,&c);  
            printf("%d\n",t[query(T[a],T[b+1],c)]);  
        }  
    }  
    return 0;  
}
