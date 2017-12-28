#include <iostream>
#include <cstring>
using namespace std;
char data[1001]={'\0'};
char pre[27],post[27];
int len,ma=0;
void process(int pre_l,int pre_r,int post_l,int post_r,int pos)
{
    if (pre_l>pre_r) return;
    data[pos]=pre[pre_l];
    ma=(ma>pos)?ma:pos;
    if (pre_l==pre_r) return;
    int i=post_l;
    while (post[i]!=pre[pre_l]) ++i;
    process(pre_l+1,pre_l+i-post_l,post_l,i-1,pos*2);
    process(pre_l+i-post_l+1,pre_r,i+1,post_r,pos*2+1);
}
int main()
{
    cin>>pre>>post;
    len=strlen(pre);
    process(0,len-1,0,len-1,1);
    for (int i=1;i<=ma;++i) if (data[i]=='\0') cout<<"NULL ";else cout<<data[i]<<' ';
}
