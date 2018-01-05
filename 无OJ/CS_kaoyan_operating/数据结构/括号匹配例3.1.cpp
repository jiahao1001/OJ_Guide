#include<stdio.h>
#include<stack>
using namespace std;
stack<int> S;
char str[100]; //输入字符串
char ans[110]; //输出字符串
int main()
{
	while(scanf("%s",str)!=EOF)
	{	
		int i;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]== '(' )
			{
				ans[i] = ' ';
				S.push(i);
			}
			else if(str[i]== ')' )
			{
				if(S.empty())
					ans[i] = '?';
				else 
				{ //匹配
					S.pop();
					ans[i] = ' ';
				}
			}
			else 
				ans[i] = ' '; //其余无关的都空
		}
		while(!S.empty()) //应该等for完成再判断
		{ //栈中还有未匹配的 '('
			ans[S.top()] = '$';
			//这句要注意,S里面都是整数，装括号的下标
			S.pop();
		}
		ans[i] = '\0';
		puts(str);
		puts(ans);
	}
	return 0;
}