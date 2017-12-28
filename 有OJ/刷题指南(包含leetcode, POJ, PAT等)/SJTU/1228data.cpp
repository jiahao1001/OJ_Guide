#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("1228.in");
    int n,i,j;
    cin>>n;
    fout<<n<<endl;
    for (i=0;i<n;++i)
    {
        for (j=0;j<n;++j) fout<<"1 ";
        fout<<endl;
    }
    fout.close();
}
