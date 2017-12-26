#include <iostream>  
using namespace std;  
  
int main()  
{  
    char ch[8010];  
    int n, sum = 0, ok = 1, c = -1;  
    scanf("%d%s", &n, ch);  
    int j = n - 1;  
    for(int i=0;i<=j-1;i++){        //从左向右依次判断  
        int k=j;
        while(str[i]!=str[k])
            k--;
            if(k == i){     //没有找到与ch[i]相同的字符  
                if(n % 2 == 0 || c != -1){      //若n为偶数或ch[i]不是唯一无法匹配的字符  
                    printf("Impossible\n");  
                    return 0;
                }  
                c = 1;              //n为奇数，ch[i]为第一个无法匹配的字符  
                sum += n / 2 - i;       //将它移到中间所需步数  
                break;  
            }  
            if(ch[k] == ch[i]){         //找到相同的  
                for(int t=k;t<=j-1;t++) ch[t] = ch[t + 1];        //往后移到对称位置  
                sum += j - k;  
                j--;  
                break;  
            }  
        }  
        if(!ok) break;  
    }  
    printf("%d\n", sum);  
    return 0;  
}  