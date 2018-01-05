/*
	已知一颗二叉树S的前序遍历和中序遍历
序列,请编程输出二叉树S的后续遍历序列.
*/
#include <stdio.h>
#include <string.h>

//在中序中查找根的下标
int FindRoot(char c, char in[], int s, int e)
{
	int i;
	for(i=s; i<=e; i++)
	{
		if(in[i] == c)
		{
			break;
		}
	}
	return i;
}

/*
 *递归遍历求得后序
 *@pre:先序序列
 *@pre_s:当前二叉树的先序序列起始下标
 *@pre_e:当前二叉树的先序序列结束下标
 *@in:中序序列
 *@in_s:当前二叉树的中序序列起始下标
 *@in_e:当前二叉树的中序序列结束下标
 */
void PostOrder(char pre[], int pre_s, int pre_e,
	char in[], int in_s, int in_e)
{
	char c;		//根节点符号
	int root;	//根节点在中序中的下标
	int l_len, r_len;//左、右子树节点数

	//当前二叉树只有一个节点(叶子节点)
	if(in_s == in_e)
	{
		printf("%c", in[in_s]);
	}
	else
	{
		//当前二叉树的根节点
		c = pre[pre_s];

		//获取根节点在中序中的下标
		root = FindRoot(c, in, in_s, in_e);

		//计算左、右子树的节点数
		l_len = root - in_s;
		r_len = in_e - root;

		//分割左子树
		if(l_len > 0)//左子树节点数不为0
		{
			PostOrder(pre, pre_s+1, pre_s+l_len,
				in, in_s, root-1);
		}

		//分割右子树
		if(r_len > 0)//右子树节点数不为0
		{
			PostOrder(pre, pre_e-r_len+1, pre_e,
				in, root+1, in_e);
		}

		//后序输出根
		printf("%c", c);
	}
}

int main()
{
	char pre[] = "ABDECFG";
	char in[]  = "DBEACGF";

	PostOrder(pre, 0, strlen(pre)-1,
		in, 0, strlen(in)-1);
	printf("\n");

	return 0;
}