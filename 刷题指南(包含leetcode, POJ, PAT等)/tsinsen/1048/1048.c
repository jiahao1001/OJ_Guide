#include <iostream>
#include <string.h>
using namespace std;


int a[10][10];
int main(){
    int n,i,j,k,c=1;
    cin>>n;

    memset(a,0,sizeof(a));

    i=j=0;

    while(n>=3){
        for(k=0;k<n-1;k++){
            a[i++][j]=c++;
        }

        for(k=0;k<n-1;k++){
            a[i][j++]=c++;
        }

        for(k=0;k<n-2;k++){
            a[i--][j--]=c++;
        }

        a[i++][j]=c++;

        n=n-3;

    }

    if(n==1)
        a[i][j]=c;

    if(n==2){
        a[i++][j]=c++;
        a[i][j++]=c++;
        a[i][j]=c;
    }



    for(i=0;i<10;i++){
        for(j=0;j<10;j++)
            if(a[i][j])
                cout<<a[i][j]<<' ';
        cout<<endl;
    }

    return 0;
}



// //标程，沿着边界向下、右、上画圈，碰到边界就执行下一步

// #include"stdio.h"
// #include"string.h"
// int main()
// {
//     int a[11][11],i,j,k,n;
//     memset(a,0,sizeof(a));
//     scanf("%d",&n);
//     a[0][0]=1;
//     for(i=0,j=0,k=2;k<=n*(n+1)/2;)
//     {
//         while(i+1<n&&a[i+1][j]==0)
//             a[++i][j]=k++;
//         while(j+1<n&&a[i][j+1]==0)
//             a[i][++j]=k++;
//         while(i-1>-1&&j-1>-1&&a[i-1][j-1]==0)
//             a[--i][--j]=k++;
//     }
//     for(i=0;i<n;i++)
//     {
//         for(j=0;j<=i;j++)
//             printf("%d ",a[i][j]);
//         printf("\n");
//     }
//     return 0;
// }
