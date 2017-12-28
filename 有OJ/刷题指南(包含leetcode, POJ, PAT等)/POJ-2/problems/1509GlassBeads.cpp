#include<stdio.h>
#include<string.h>
char s[10010];
int getminsub(char *a)
{
    int i=0,j=1,len=strlen(a),k=0; //取两个同构的字符串一个从下标0开始，一个从下标1开始
    while(i<len&&j<len&&k<len) //这里并没有将字符串复制一份添加到后面
    {
        if(k==len) break; //说明找到了a的最小表示
        if(i==j) j++;
        int ni=i+k,nj = j+k;
        if(ni>=len) ni-=len; //就是回到字符串的开始去
        if(nj>=len) nj-=len;
        if(a[ni]>a[nj])
        {
            i+=k+1;
            k=0;
        }
        else if(a[ni]<a[nj])
        {
            j+=k+1;
            k=0;
        }
        else k++;
    }
    return  i; //返回从第i个字符开始时a的最小表示
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		printf("%d\n",getminsub(s)+1);
	}
	return 0;
}
