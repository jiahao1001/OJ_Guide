#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s,s1,s2,s3;
    int m,n;
    s1="int";
    s2="char";
    s3="double";
    cin>>s;
    if(s==s1)
    {
        int *a1,*a2,*a3;
        a1=new int[10000];
        a2=new int[10000];
        a3=new int[20000];
        cin>>m>>n;
        for(int i=0;i<m+n;i++)
        {
            cin>>a3[i];
        }
        for(int i=0;i<m+n;i++)
        {
            cout<<a3[i]<<" ";
        }
    }
    if(s==s2)
    {
        char *a1,*a2,*a3;
        a1=new char[10000];
        a2=new char[10000];
        a3=new char[20000];
        cin>>m>>n;
        for(int i=0;i<m+n;i++)
        {
            cin>>a3[i];
        }
        for(int i=0;i<m+n;i++)
        {
            cout<<a3[i]<<" ";
        }
    }
    if(s==s3)
    {

        double *a1,*a2,*a3;
        a1=new double[10000];
        a2=new double[10000];
        a3=new double[20000];
        cin>>m>>n;
        for(int i=0;i<m+n;i++)
        {
            cin>>a3[i];
        }
        for(int i=0;i<m+n;i++)
        {
            cout<<a3[i]<<" ";
        }
    }

    return 0;


}
