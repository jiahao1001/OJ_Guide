#include<iostream>
#include<string.h>
using namespace std;
const int MOD = 10007;
struct Matrix{
    int M[4][4];
    Matrix(){
        memset(M,0,sizeof M);
    }
    Matrix operator*(const Matrix &b){
        Matrix c;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                for(int k=0;k<4;k++) c.M[i][j] += M[i][k]*b.M[k][j], c.M[i][j]%=MOD;
        return c;
    }
};
int main(){
    int t;
    int A[4][4]=
        { {2,1,1,0},
          {1,2,0,1},
          {1,0,2,1},
          {0,1,1,2}};
    Matrix M;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++) M.M[i][j] = A[i][j];
    
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        Matrix C;
        for(int i=0;i<4;i++) C.M[i][i] = 1;
        Matrix B = M;
        while(n){
            if(n&1) C = C*B;
            B = B*B;
            n/=2;
        }
        
        printf("%d\n",C.M[0][0]);
    }
}
