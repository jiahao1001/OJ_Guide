#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    //ifstream fin("1010.in");
    int data[12];
    int i,r=0,t,tt=0;
    for (i=0;i<12;++i) cin>>data[i];
    //fin.close();
    for (i=0;i<12;++i)
    {
        //cout<<r<<' '<<data[i]<<endl;
        r+=300;
        if (r<data[i])
        {
            cout<<-1-i<<'\n';
            return 0;
        }
        t=(r-data[i])/100;
        r=r-data[i]-t*100;
        tt+=t;
    }
    cout<<r+tt*120<<'\n';
}
