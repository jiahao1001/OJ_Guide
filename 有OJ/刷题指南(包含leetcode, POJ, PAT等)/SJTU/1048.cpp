#include <iostream>
using namespace std;
void ins(int x,int* tree,int pos,int* index,int* left,int* right)
{
    tree[pos]=x+1;
    if (index[x]!=-1)
    {
        ins (left[index[x]],tree,pos*2+1,index,left,right);
        ins (right[index[x]],tree,pos*2+2,index,left,right);
    }
}
int main()
{
    int n,i,x;
    cin>>n;
    int* tree=new int[n];
    int* index=new int[n];
    int* left=new int[n/2];
    int* right=new int[n/2];
    bool* p=new bool[n];
    for (i=0;i<n;++i)
    {
        index[i]=-1;
        p[i]=true;
    }
    for (i=0;i<n/2;++i)
    {
        cin>>x>>left[i]>>right[i];
        --left[i];
        --right[i];
        index[x-1]=i;
        p[left[i]]=false;
        p[right[i]]=false;
    }
    for (i=0;i<n;++i) if (p[i])
    {
        x=i;
        break;
    }
    ins(x,tree,0,index,left,right);
    for (i=0;i<n;++i) cout<<tree[i]<<endl;
    delete [] tree;
    delete [] index;
    delete [] left;
    delete [] right;
    delete [] p;
}
