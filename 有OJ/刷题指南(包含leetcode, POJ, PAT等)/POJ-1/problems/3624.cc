#include <iostream>
int dp[12881] = {0};
int main() 
{ 
    int N, M;
    std::cin>>N>>M;
    for (int i=0; i<N; i++)
    {
        int w, v;
        std::cin>>w>>v;
        for (int j=M; j>=w; j--)
        {
            if (j >= w && (dp[j-w]+v) > dp[j]) {
                dp[j] = dp[j-w]+v;
            }
        }
    }
    std::cout<<dp[M]<<std::endl;
    return 0;
}