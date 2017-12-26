#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stack>
#define N 20010
#define M 2000010
using namespace std;
struct edge
{
    int u,v,next;
}elist[M];
int ne; //ne=0 head[N]=-1;
int n,m,k;
int color[M]; // 0 not vis, 1 grey 2 black, in circle
int vis[N];
int head[N];
void addedge(int u,int v)
{
    elist[ne].next=head[u], elist[ne].u=u,elist[ne].v=v,head[u]=ne++;
    elist[ne].next=head[v], elist[ne].u=v,elist[ne].v=u,head[v]=ne++;
}
int circle[M>>1];
int cnt;
stack<int> S;

void dfs(int u,int f,int ei)
{
    vis[u]=1;
//    cout<<"v"<<u<<endl;
    if(f) S.push(ei);
    for(int j=head[u];j!=-1;j=elist[j].next)
        if(elist[j].v!=f && color[j]!=2 ){
            if(vis[elist[j].v]==1)
            {
                //              cout<<"circle "<<elist[j].v<<endl;
                color[j]=color[j^1]=2;
                //cout<<elist[j].u<<" "<<elist[j].v<<endl;
                int tmp=1;
                int le;
                int prevu=elist[j].u;
                int flag=1;
                while(!S.empty())
                {
                    le=S.top();
                    
                    color[le]=color[le^1]=2;
                    //  cout<<elist[le].u<<" "<<elist[le].v<<endl;
                    S.pop();
                    if(prevu==elist[le].v)
                        prevu=elist[le].u,tmp++;
                    if(elist[le].u==elist[j].v) break;
                    
                }
                if(tmp!=0 && prevu != elist[j].v) tmp=0;
                
                circle[cnt++]=tmp;
                //cout<<tmp<<endl;
            }
            else dfs(elist[j].v,u,j);
        }
    
}
class Solution {
public:
    
    string add(string num1,string num2){
        if(num1.size()<num2.size()) swap(num1,num2);
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        int x,y;
        while(j>=0 || i>=0){
            
            if(i>=0)x=num1[i]-'0';
            else x=0;
            if(j>=0)y=num2[j]-'0';
            else y=0;
            num1[i]=(x+y+carry)%10+'0';
            carry=(x+y+carry)/10;
            j--,i--;
        }
        if(carry) num1="1"+num1;
        return num1;
    }
    string mul(string num,int n,int zeros){
        int carry=0;
        int j=num.size()-1;
        for(;j>=0;j--){
            int x=num[j]-'0';
            num[j]=((x*n)+carry)%10+'0';
            carry=(x*n+carry)/10;
        }
        if(carry) num=char(carry+'0')+num;
        return num.append(zeros,'0');
        
    }
    
    string multiply(string num1, string num2) {
        string ans="0";
        for(int j=num2.size()-1,zero=0;j>=0;j--,zero++){
            ans=add(ans,mul(num1,num2[j]-'0',zero));
        }
        
        while(ans.size()>1&&ans[0]=='0') ans=ans.substr(1);
        return ans;
    }
};
string toString(int num)
{
    string s="";
    while(num) s+=('0'+(num%10)),num/=10;
    string t=s;
    int len=s.size();
    for(int i=0;i<s.size();i++)
        t[i]=s[len-1-i];
    return t;
    
}

int main()
{
    ne=0;
    int u,v;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&k);
        scanf("%d",&u);
        for(int i=1;i<k;i++)
        {
            scanf("%d",&v);
            addedge(u,v);
            u=v;
        }
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            printf("0\n");
            return 0;
        }
    for(int i=0;i<cnt;i++)
        if(!circle[i]){
            printf("0\n");
            return 0;
        }
    Solution s;
    string ans="1";
    for(int i=0;i<cnt;i++)
        //cout<<circle[i]<<endl,
        ans=s.multiply(ans,toString(circle[i]+1));
    
    cout<<ans<<endl;
    
    return 0;
} 
