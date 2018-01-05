#include<stdio.h>
#include<stack>
using namespace std;
char str[220];
int mat[][5]=
{   //+,-,*,/
	1,0,0,0,0, //要有5行，不然'/'用不了
	1,0,0,0,0,
	1,0,0,0,0,
    1,1,1,0,0,
	1,1,1,0,0
};
//mat[A][B] 即A的优先级和B的比较，1表示较高
stack<int> op; //运算符栈
stack<double> in; //数字栈
void getOp(bool &reto,int &retn,int &i)
{ //reto为false，则表示数字，存入retn中
  //reto为true，则表示运算符，存入retn中。
  //i表示遍历到的字符串下标
	if(i==0&&op.empty()==true)
	{ //第一个字符，且运算符栈为空，加0标记
		reto = true;
		retn = 0;
		return; //此处为了跳出函数
	}
	if(str[i]=='\0')
	{ //到了最后一个，加0标记
		reto = true;
		retn = 0;
		return;
	}
	if(str[i]>='0'&&str[i]<='9')
	{ //遍历数字，则转化为int型
		reto = false;
		retn = 0;
		for(;str[i]!=' '&&str[i]!='\0';i++)
		{
			retn*=10;
			retn+=(str[i]-'0');
		}
		if(str[i]==' ')
			i = i+1;
		return;
	}
	else
	{ //遍历运算符
		reto = true;
		if(str[i]=='+')
			retn = 1;
		else if(str[i]=='-')
			retn = 2;
		else if(str[i]=='*')
			retn = 3;
		else if(str[i]=='/')
			retn = 4;
		i+=2;
		return;
	}
}
int main()
{
	while(gets(str))
	{
		if(str[0]=='0'&&str[1]=='\0')
			break;
		bool retop; 
		int retnum;
		int idx = 0;
		while(!op.empty())
			op.pop();
		while(!in.empty())
			in.pop();
	while(true)
	{  //一直在此循环
		getOp(retop,retnum,idx);
		if(retop==false)
			in.push((double)retnum);
		else
		{ //为运算符
			if(op.empty()||mat[retnum][op.top()]==1)
				op.push(retnum); //栈空或优先级更高
				//如 1 + 2 * 3
			else
			{ //否则开始计算
				double tmp;
				while(mat[retnum][op.top()]==0)
				{
					int ret = op.top();
					op.pop(); //因为pop()操作是void型的，所以只能这样
					double b = in.top();
					in.pop();
					double a = in.top(); //栈和输入的顺序相反，所以要倒过来
					in.pop();
					if(ret == 1)
						tmp = a + b;
					else if(ret == 2)
						tmp = a - b;
					else if(ret == 3)
						tmp = a * b;
					else if(ret == 4)
						tmp = a / b;
					in.push(tmp);					
				}
				op.push(retnum); 
				//计算完上一步后还有一个运算符，要把它压入栈中
				//如 2 * 3 + 1 ；在得到'+'后，要将前面的2*3计算出来，然后把'+'入栈
			}
		}
		if(op.size()==2&&op.top()== 0 )  //这个0一定不能写成'0'
			break; //如果运算符栈只剩两个标记了，就表示已完成
	}//while(true)
	printf("%.2f\n",in.top());
	}//while(gets(str))
	return 0;
}