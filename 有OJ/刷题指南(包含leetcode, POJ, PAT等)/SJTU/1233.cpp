#include <cstdio>
int n,m,start,M,res=0;
struct node
{
    int data;
    node *next;
    node(){data=0;next=NULL;}
};
node *points;
bool *visited,*end;
void add(int a,int b)
{
    node *tmp=&points[a];
    while (tmp->next!=NULL) tmp=tmp->next;
    tmp->next=new node;
    tmp->next->data=b;
    tmp->next->next=NULL;
}
void search(int s,int len)
{
    if (len==0 && end[s])
    {
        ++res;
        end[s]=false;
        return;
    }
    node *p=points[s].next;
    visited[s]=true;
    while (p!=NULL)
    {
        if (!visited[p->data]) search(p->data,len-1);
        p=p->next;
    }
    visited[s]=false;
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&start,&M);
    int i,j,a,b;
    points=new node[n+1];
    visited=new bool[n+1];
    end=new bool[n+1];
    for (i=0;i<=n;++i)
    {
        points[i].next=NULL;
        visited[i]=false;
        end[i]=true;
    }
    for (i=0;i<m;++i)
    {
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    search(start,M);
    printf("%d\n",res);
    delete [] visited;
    delete [] end;
}
