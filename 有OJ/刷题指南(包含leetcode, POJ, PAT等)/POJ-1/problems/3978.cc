#include <iostream>
int main()
{
    int primenum[10000] = {0};
    bool prime[10000] = {true, true};
    for (int i=2; i<10000; i++)
    {
        primenum[i] = primenum[i-1];
        if (prime[i] == true) {
            continue;
        }
        for (int j=i+i; j<10000; j+=i) {
            prime[j] = true;
        }
        primenum[i]++;
    }
    int a, b;
    std::cin>>a>>b;
    while (a!=-1 || b!=-1) {
        if (a<=0) {
            a=1;
        }
        std::cout<<primenum[b]-primenum[a-1]<<std::endl;
        std::cin>>a>>b;
    }
    return 0;
}
