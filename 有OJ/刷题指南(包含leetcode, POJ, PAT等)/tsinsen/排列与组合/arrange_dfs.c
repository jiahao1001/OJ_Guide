
//采用dfs实现全排列

#include <stdio.h>

#define NUM 5

int n = 0;
int b[NUM]={0};   //标记元素是否被使用
int res[NUM];     //记录结果字符串

void dfs(int a[], int m){
    int i;
    if(m==0){
        for(i=0;i<NUM;i++){
            printf("%d",res[i]);
        }
        printf("\n");
        n++;
    }
    else{
        for(i=0;i<NUM;i++){
            if(!b[i]){
                b[i]=1;
                res[NUM-m]=a[i];
                dfs(a,m-1);
                b[i]=0;
            }
        }
    }
}


int main()
 
{
 
  int list[] = {1, 2, 3, 4, 5};
 
  dfs(list,5);
 
  printf("total:%d\n", n);
 
  return 0;
 
}