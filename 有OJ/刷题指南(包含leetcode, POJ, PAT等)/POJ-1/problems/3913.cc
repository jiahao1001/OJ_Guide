#include <iostream>
int main()
{
    int n;
    std::cin>>n;
    std::cout<<"Gnomes:"<<std::endl;
    for (int i=0; i<n; i++)
    {
        int a, b, c;
        std::cin>>a>>b>>c;
        if ((a<b && b<c) || (a>b && b>c)) {
            std::cout<<"Ordered"<<std::endl;
        }
        else std::cout<<"Unordered"<<std::endl;
    }
    return 0;
}
