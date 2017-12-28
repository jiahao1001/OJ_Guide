#include <cstdio>
const int BASE=500009;
class point
{
private:
    int key,value;
public:
    point(int k)
    {
        key=k;
        value=1;
    }
    bool compare(int k)
    {
        return (key==k);
    }
    int csgo()
    {
        return value;
    }
    void add(){++value;}
};
int pot(int n)
{
    return (n>=0)?n:-n;
}
int n;
point* hash[BASE];
int main()
{
    freopen("1224.in","r",stdin);
    scanf("%d",&n);
    int *A=new int[n],*B=new int[n],*C=new int[n],*D=new int[n];
    int i,j,k,t,res=0;
    for (i=0;i<n;++i)
    {
        scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
    }
    for (i=0;i<BASE;++i) hash[i]=NULL;
    for (i=0;i<n;++i) for (j=0;j<n;++j)
    {
        t=pot(A[i]+B[j]);k=0;
        while (hash[(t+k*k)%BASE]!=NULL && !(hash[(t+k*k)%BASE]->compare(A[i]+B[j]))) ++k;
        if (hash[(t+k*k)%BASE]==NULL)
        {
            hash[(t+k*k)%BASE]=new point(A[i]+B[j]);
            //printf("new %d\n",A[i]+B[j]);
        }
        else
        {
            hash[(t+k*k)%BASE]->add();
            //printf("++ %d\n",A[i]+B[j]);
        }
    }
    for (i=0;i<n;++i) for (j=0;j<n;++j)
    {
        t=pot(-C[i]-D[j]);k=0;
        //printf("search %d\n",A[i]+B[j]);
        while (hash[(t+k*k)%BASE]!=NULL && !(hash[(t+k*k)%BASE]->compare(-C[i]-D[j]))) ++k;
        if (hash[(t+k*k)%BASE]!=NULL) res+=hash[(t+k*k)%BASE]->csgo();
    }
    printf("%d\n",res);
    delete [] A;
    delete [] B;
    delete [] C;
    delete [] D;
    for (i=0;i<BASE;++i) if (hash[i]!=NULL) delete hash[i];
}
