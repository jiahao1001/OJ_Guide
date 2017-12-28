#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    ofstream fout("1265.in");
    fout<<n<<'\n';
    srand(time(NULL));
    for (int i=0;i<m;++i)
    {
        int j=rand()%2+1;
        fout<<j<<' ';
        if (j==1) fout<<rand()%n<<' '<<rand()%n<<' '<<rand()%10<<'\n';
        else fout<<rand()%n<<' '<<rand()%n<<' '<<rand()%n<<' '<<rand()%n<<'\n';
    }
    fout<<"3";
    fout.close();
}
