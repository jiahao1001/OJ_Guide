#include <stdafx.h>
#include <iostream>
using namespace std;


int main () {
   int a[100][100];
   int n,m,i,j,max,flag=0;
   cin>>n>>m;
   for(i=0;i<n;i++){
	   for(j=0;j<m;j++){
		   cin>>a[i][j];
	   }
   }
   for(j=0;j<m;j++){
	   max=0;
	   flag=0;
	   for(i=0;i<n;i++){
		   if(!flag){
			   if(a[i][j]!=0){
				   max=i;
				   flag=1;
			   }
		   }
		   else if(a[i][j]!=0&&a[i][j]<=a[max][j]){
			   flag=1;
			   max=i;
		   }
	   }

	   if(!flag)
		   cout<<"0 ";
	   else
		   cout<<max+1<<" ";
   }
   cin>>i;

   return 0;
}



//标程，与我最初思路相同
//单价不会超过100
//#include"stdio.h"
//int main()
//{
//    int a[52][101],i,j,m,min,n;
//    scanf("%d %d",&n,&m);
//    for(i=1;i<=n;i++)
//        for(j=0;j<m;j++)
//            scanf("%d",&a[i][j]);
//    for(i=0;i<m;i++)
//    {
//        min=0;
//        a[0][i]=100;
//        for(j=1;j<=n;j++)
//            if(a[j][i]&&a[j][i]<=a[min][i])
//                min=j;
//        printf("%d ",min);
//    }
//    return 0;
//}