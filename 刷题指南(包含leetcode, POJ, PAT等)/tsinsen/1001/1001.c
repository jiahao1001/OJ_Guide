#include<iostream>
#include<bitset>
using namespace std;
 

// 采用bitset方法
int main()
{
    for(int i=0;i<64;i++)
    {
        cout << bitset<6>(i) << endl;
    }
    return 0;
}