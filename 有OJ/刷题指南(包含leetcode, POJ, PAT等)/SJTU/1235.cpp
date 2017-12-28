#include <cstdio>
struct node
{
    int from,to,weight;
    node(int f=-1,int t=-1,int w=-1):from(f),to(t),weight(w){}
};
int visited[10010]={0};
int prev[10010]={0};
int n,m,start,end;
class priorityQueue
{
private:
    int size;
    node *data;
    void percolateDown(int hole)
    {
        int child;
        node tmp=data[hole];
        for (;hole*2<=size;hole=child)
        {
            child=hole*2;
            if (child < size && data[child+1].weight < data[child].weight) ++child;
            if (data[child].weight < tmp.weight) data[hole]=data[child];
            else break;
        }
        data[hole]=tmp;
    }
public:
    priorityQueue()
    {
        size=0;
        data=new node[200010];
    }
    ~priorityQueue()
    {
        delete [] data;
    }
    bool isEmpty()
    {
        return (size==0);
    }
    void enqueue(node t)
    {
        int hole=++size;
        for(;hole>1 && t.weight < data[hole/2].weight;hole/=2) data[hole]=data[hole/2];
        data[hole]=t;
    }
    node dequeue()
    {
        node res=data[1];
        data[1]=data[size--];
        percolateDown(1);
        return res;
    }
};
struct Link
{
    int data,weight;
    Link *next;
    Link():data(0),weight(0),next(NULL){}
};
Link divergent[10010];
void add(int a,int b,int w)
{
    Link *p=&divergent[a];
    while (p->next!=NULL && p->data!=b) p=p->next;
    if (p->data==b)
    {
        if (p->weight > w) p->weight=w;
    } else
    {
        p->next=new Link;
        p->next->data=b;
        p->next->weight=w;
        p->next->next=NULL;
    }
}
int route[10010];
int main()
{
    freopen("1235.in","r",stdin);
    scanf("%d %d %d %d",&n,&m,&start,&end);
    int i,cnt=0,x,y,z;
    for (i=1;i<=n;++i)
    {
        visited[i]=-1;
        prev[i]=-1;
    }
    for (i=1;i<=m;++i)
    {
        scanf("%d %d %d",&x,&y,&z);
        add(x,y,z);
    }
    priorityQueue q;
    visited[start]=0;
    Link *p=divergent[start].next;
    node tmp;
    while (p!=NULL)
    {
        q.enqueue(node(start,p->data,p->weight));
        p=p->next;
    }
    while (visited[end]==-1)
    {
        while (1)
        {
            tmp=q.dequeue();
            if (visited[tmp.to]==-1) break;
        }
        visited[tmp.to]=visited[tmp.from]+tmp.weight;
        prev[tmp.to]=tmp.from;
        p=divergent[tmp.to].next;
        while (p!=NULL)
        {
            q.enqueue(node(tmp.to,p->data,p->weight));
            p=p->next;
        }
    }
    for (i=end;i!=-1;i=prev[i]) route[++cnt]=i;
    printf("%d\n",visited[end]);
    for (i=cnt;i>0;--i)printf("%d ",route[i]);
}
