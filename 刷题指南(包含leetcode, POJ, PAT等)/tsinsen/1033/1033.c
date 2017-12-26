#include <iostream>
#include <string.h>

using namespace std; 


//递归
//起点永远在对角线上
//从起点开始顺时针画一圈，这是递归的一个过程
//然后再进入第二个递归中，开始第二个圈


int matrix[31][31]; 

void circle(int start, int n, int count){
    if(n<=0)return;
    if(n==1){
        matrix[start][start]=count;
        return;
    }


    int i;

    //以顺时针方向开始循环一圈
    for(i=0;i<n;i++){
        matrix[start][start+i]=count++;
    }
    for(i=1;i<n;i++){
        matrix[start+i][start+n-1]=count++;
    }
    for(i=n-1;i>0;i--){
        matrix[start+n-1][start+i-1]=count++;
    }
    for(i=n-1;i>1;i--){
        matrix[start+i-1][start]=count++;
    }

    circle(start+1,n-2,count);


}

int main(){
    memset(matrix,0,sizeof(matrix));

    int n,i,j;
    cin>>n;

    circle(0,n,1);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<matrix[i][j]<<' ';
        cout<<endl;
    }

    return 0;
}