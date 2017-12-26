#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int N = 20;
typedef long long LL;
LL Td[N+1][N+1];
LL Tu[N+1][N+1];
int answer[N+1];
int main()
{
        int k,n;
        long long C;
        scanf("%d",&k);
        Td[1][1] = 1;
        for(int i=1;i<=N;i++){
                for(int j=1;j+1<=N;j++) Td[i][j+1] = Td[i][j]+Tu[i-1][j];
                for(int j=1;j<=N;j++) Tu[i][j]= Td[i][i+1-j];
        }
        //cout<<Tu[2][1]<<endl;
        while(k--){
                scanf("%d%lld",&n,&C);
                if(n==1){
                        printf("1\n");
                        continue;
                }
                long long tot = 0;
                int a1;
                for(a1=1;a1<=N;a1++){
                        tot += Td[n][a1]+Tu[n][a1];
                        if(tot>=C) break;
                }
                bool up = true;
                int a2,y;
                tot -= Td[n][a1]+Tu[n][a1];
                long long C1 = C-tot;
                tot = 0;
                long long last = 0;
                for(y=1;y<=n-1;y++){
                        if(y<a1) tot+=Tu[n-1][y],last = Tu[n-1][y];
                        else tot+=Td[n-1][y],last = Td[n-1][y];
                        if(tot>=C1) break;
                }
                if(y<a1) a2=y, up = false;
                else a2 = y+1, up = true;
//              cout<<up<<endl;
                answer[1] = a1, answer[2] = y;
                C = C1-(tot-last);
                for(int i=3;i<=n;i++){
                        tot = 0;
                        int a=1;
                        if((i%2==1 && !up)||(i%2==0 &&up)){
                                for(a=answer[i-1];a<=n-i+1;a++){
                                        tot+=Td[n-i+1][a],last = Td[n-i+1][a];
                                        if(tot>=C) break;
                                }
                        }else{
                                for(a=1;a<answer[i-1];a++){
                                        tot += Tu[n-i+1][a], last = Tu[n-i+1][a];
                                        if(tot>=C) break;
                                }

                        }
                        answer[i] = a;
                        C = C-(tot-last);
                }
                for(int i=n;i>=1;i--){
                        for(int j=i-1;j>=1;j--) if(answer[i]>=answer[j]) answer[i]++;
                }
                for(int i=1;i<=n;i++){
                        if(i==1)printf("%d",answer[i]);
                        else printf(" %d",answer[i]);
                }
                printf("\n");
        }
        return 0;
}
