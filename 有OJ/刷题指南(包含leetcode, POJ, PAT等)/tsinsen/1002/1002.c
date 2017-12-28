#include<iostream>
#include<bitset>
using namespace std;
 

// 采用bitset方法
int main()
{
    for(int i=0;i<64;i++)
    {
        bitset<6> bt(i);
        int count=0;
        for(int j=0;j<6;j++){
            if(bt[j]==1)
                count++;
        }
        if(count%2==1)cout<<bt<<endl;
    }
    return 0;
}