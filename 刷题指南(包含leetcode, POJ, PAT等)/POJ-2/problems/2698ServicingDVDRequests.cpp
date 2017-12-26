#include<iostream>
#include<map>
using namespace std;
int m,k,n;
int r[100];
int drive[10];
map<int,int> id;
int get(int d,int j){
    int ret = 999999999;
    for(int i=j;i<n;i++){
        if(id[r[i]]==d) return i;
    }
    return ret;
}
int main()
{
    scanf("%d",&m);
    while(m--){
        id.clear();
        int cnt = 0;
        scanf("%d%d",&k,&n);
        for(int i=0;i<n;i++) scanf("%d",r+i);
        for(int i=0;i<n;i++) if(!id.count(r[i])) id[r[i]] = cnt++;
        int i_cnt = 0;
        int j = 0;
        int ans =0;
        while(i_cnt<k && j<n){
            int d = id[r[j]];
            int i = 0;
            for(i=0;i<i_cnt;i++)
                if(drive[i]==d) break;
            if(i==i_cnt) drive[i_cnt++] = d,ans++;
            j++;
        }
        
        //printf("-----------\n");
        //for(int i=0;i<k;i++) printf("%d\n",drive[i]);
        //printf("---------\n");
        
        while(j<n){
            int d = id[r[j]];
            int i=0;
            for(i=0;i<k;i++)
                if(drive[i]==d) break;
            if(i==k){
                //printf("needed\n");
                //find one and swap
                int best = 0,id = 0;
                for(int l=0;l<k;l++){
                    int t = get(drive[l],j);
                    if(t>best) best = t, id = l;
                }
                drive[id] = d;
                ans ++;
            }
            j++;
        }
        
        printf("%d\n",ans);
    }
    return 0;
}
