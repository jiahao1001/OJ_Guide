#include <iostream>
using namespace std;
int main()
{
    int m,t,u,f,d,i;char p;bool flag=true;
    cin>>m>>t>>u>>f>>d;
    int x=u+d,y=f*2;
    for (i=0;i<t;++i)
    {
        cin>>p;
        if (flag)
        {
            switch (p)
            {
                case 'u':
                case 'd':u=x;
                         break;
                case 'f':u=y;
                         break;
            }
            m-=u;
            if (m<0)
            {
                f=i;
                flag=false;
            }
        }
    }
    cout<<f;
}
