#include <cstdio>
#include <queue>
using namespace std;
int n;
struct node
{
    int data;
    node *next;
    node(){data=0;next=NULL;}
};
node *out;
void add(int a,int b)
{
    ++out[b].data;
    node *tmp=&out[a];
    while (tmp->next!=NULL) tmp=tmp->next;
    tmp->next=new node;
    tmp->next->data=b;
    tmp->next->next=NULL;
}
int main()
{
    int m,i,j,a,b;
    scanf("%d %d",&n,&m);
    out=new node[n+1];
    for (i=0;i<m;++i)
    {
        scanf("%d %d",&b,&a);
        add(a,b);
    }
    queue<int> q1,q2;
    int t=1;
    for (int i=1;i<=n;++i) if (out[i].data==0)
    {
        q1.push(i);
        q2.push(1);
    }
    node *tmp;
    while (!q1.empty())
    {
        j=q1.front();
        t=q2.front();
        q1.pop();
        q2.pop();
        tmp=out[j].next;
        while (tmp!=NULL)
        {
            --out[tmp->data].data;
            if (out[tmp->data].data==0)
            {
                q1.push(tmp->data);
                q2.push(t+1);
            }
            tmp=tmp->next;
        }
    }
    printf("%d\n",t);
}
