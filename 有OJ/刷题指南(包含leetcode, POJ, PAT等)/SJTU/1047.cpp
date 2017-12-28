#include <iostream>
using namespace std;
int minn=100;
int ans[9]={0};
int data[9];
int res[9]={0};
void move(int t,int* c)
{
    switch (t)
    {
        case 1:c[0]=(c[0]+1)%4;
               c[1]=(c[1]+1)%4;
               c[3]=(c[3]+1)%4;
               c[4]=(c[4]+1)%4;
               break;
        case 2:c[0]=(c[0]+1)%4;
               c[1]=(c[1]+1)%4;
               c[2]=(c[2]+1)%4;
               break;
        case 3:c[1]=(c[1]+1)%4;
               c[2]=(c[2]+1)%4;
               c[4]=(c[4]+1)%4;
               c[5]=(c[5]+1)%4;
               break;
        case 4:c[0]=(c[0]+1)%4;
               c[3]=(c[3]+1)%4;
               c[6]=(c[6]+1)%4;
               break;
        case 5:c[1]=(c[1]+1)%4;
               c[3]=(c[3]+1)%4;
               c[4]=(c[4]+1)%4;
               c[5]=(c[5]+1)%4;
               c[7]=(c[7]+1)%4;
               break;
        case 6:c[2]=(c[2]+1)%4;
               c[5]=(c[5]+1)%4;
               c[8]=(c[8]+1)%4;
               break;
        case 7:c[3]=(c[3]+1)%4;
               c[4]=(c[4]+1)%4;
               c[6]=(c[6]+1)%4;
               c[7]=(c[7]+1)%4;
               break;
        case 8:c[6]=(c[6]+1)%4;
               c[7]=(c[7]+1)%4;
               c[8]=(c[8]+1)%4;
               break;
        case 9:c[4]=(c[4]+1)%4;
               c[5]=(c[5]+1)%4;
               c[7]=(c[7]+1)%4;
               c[8]=(c[8]+1)%4;
               break;
    }
}
bool check()
{
    int i;
    for (i=0;i<9;++i) if (data[i]!=3) return false;
    return true;
}
bool compare()
{
    int i,t=0;
    for (i=0;i<9;++i) t+=res[i];
    if (t<minn)
    {
        minn=t;
        return true;
    }
    if (t>minn) return false;
    for (i=0;i<9;++i) if (res[i]<ans[i]) return false;else if (res[i]>ans[i]) return true;
}
void search(int n)
{
    if (check())
    {
        if (compare())
        {
            for (int i=0;i<9;++i) ans[i]=res[i];
            return;
        }
    }
    if (n==9) return;
    for (int i=0;i<3;++i)
    {
        search(n+1);
        move(n+1,data);
        ++res[n];
    }
}
int main()
{
    int i,j;
    for (i=0;i<9;++i)
    {
        cin>>data[i];
        data[i]=data[i]/3-1;
    }
    search(0);
    for (i=0;i<9;++i) for (j=0;j<ans[i];++j) cout<<i+1<<' ';
}
