#include <stdio.h>  
  
int main()  
{  	freopen("2034.in", "r", stdin);
	freopen("2034.out", "w", stdout);
    int n,m;              // 定义变量，含义如题  
    
  
    while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0))     // 输入语句，多个测试实例，且以0，0结束。  
    {  
        int i,j,t;                  // 此处的临时变量，i, j为循环变量，t为临时存储数据变量  
        int flag=0;                 // 标识变量  
        int a[101],b[101];          // a[]; b[]; 为存储两个集合的整型数组  
        int c[101]={0};             // c[]; 为用于存储集合的差的数组，此处的初始化，用memset(); 函数更合适和恰当。。  
        for(i=0;i<n;i++)    
            scanf("%d",&a[i]);  
        for(i=0;i<m;i++)  
            scanf("%d",&b[i]);      // 从标准输入读入两个集合，并存入对应的的数组中  
  
        // 由于要求输出结果为从大到小，所以对A数组进行排序，用冒泡排序也可以。。。  
        for(i=1;i<n;i++)         
        {  
            t=a[i];  
            for(j=i;j>0;j--)  
            {  
                if(t<a[j-1])                      
                    a[j]=a[j-1];      
                else  
                    break;  
            }  
            a[j]=t;  
        }   
          
        for(i=0;i<n;i++)  
        {  
            for(j=0;j<m;j++)  
                if(a[i]==b[j])  
                    break;  
                if(j>=m)  
                    c[flag++]=a[i];  
        }                        // 用已经排好序的A数组的元素逐个与B数组的元素比较，  
                                 // 如有相等的，则是标致变量加一， 并将相等的数组元素存入数组C中  
  
        if(flag==0)  
            printf("NULL");  
        else  
        {  
            for(i=0;i<flag;i++)  
                printf("%d ",c[i]);       // 注意，此处不需要注意最后的末尾是否不含有空格，题目已经解释含有空格  
        }                       // 依据标识变量的值输出结果，NULL或者数组C。  
        printf("\n");         
    }  
  
    return 0;  
}  
