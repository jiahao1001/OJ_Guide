#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a,b;vector<int> v;
    while (cin>>a>>b) v.push_back(a+b);
    a=v.size();
    for (b=0;b<a;++b) cout<<v[b]<<endl;
}
