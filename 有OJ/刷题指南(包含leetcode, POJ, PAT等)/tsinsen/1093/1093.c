 #include <iostream>
using namespace std;
int main()
{
    int i;
    cin>>i;
    if(i % 400 == 0 || i % 4 == 0 && i % 100 != 0 )
    cout<<"yes";
    else
    cout<<"no";
    return 0;
}