#include <stdio.h> 
#include <stdlib.h>
#define N 255
int MaxSubString(char *str1,char *str2,char s[])
{ 
	int i, j, k, index, max=0;
	for(i=0; str1[i]; i++)  //字符串str1
		for(j=0; str2[j]; j++)  //字符串str2
		{ 
			for(k=0; str1[i+k]==str2[j+k] && (str2[j+k] || str1[i+k]); k++);
			if(k>max) 
			{
				index = j; max = k; //k记录本次相同子串，max记录当前最大子串，如果本次子串个数>max，max更新为k
			}  
		}
		for(i=0; i<max; i++) s[i] = str2[index++];
		return max; 
}

int  main() 
{
	int length; 
	char str1[N],str2[N],s[N];
	printf("Please input two strings:\n"); 
	gets(str1); 
	gets(str2);
	length = MaxSubString(str1, str2,s);
	printf("str1: %s\n",str1); 
	printf("str2: %s\n",str2);
	printf("MaxSubString: %s\n",s);
	printf("length=%d\n",length); 
	system("pause" ); 
	return 0; 
}
