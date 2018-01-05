/* 1.二叉树的前中后序遍历，求树的高度。
 * 2.由先序遍历和中序遍历构造二叉树。
 * 3.并查集
 */
#include "binaryTree.h"

void findIJAncestor(int T[],int i,int j) {
	while(i != j) {
		if (i > j)
			i = i/2;
		else
			j = j/2;
	}
	cout<<"The common ancestor is "<<i<<" "<<T[i]<<endl;
}

// question2
BiTree createTwithPreIn(int pre[], int in[], int l1, int h1, int l2, int h2){
	BiTNode *root = (BiTree)malloc(sizeof(BiTNode));
	root->data = pre[l1];
	int i, llen, rlen;
	for (i = l2; in[i] != root->data; ++i);
	if (i > h2){
		cout<<root->data<<" i="<<i<<" h2="<<h2<<endl;
		exit(-1);
	}
	llen = i - l2;
	rlen = h2 - i;
	if (llen)
		root->lchild = createTwithPreIn(pre, in, l1 + 1, l1 + llen, l2, l2 + llen - 1);
	else
		root->lchild = NULL;
	if (rlen)
		root->rchild = createTwithPreIn(pre, in, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
	else
		root->rchild = NULL;
	return root;
}

// question3

int main(int argc, char const *argv[])
{
	// int A[100];
	// findIJAncestor(A, 30, 90);
	BiTree t = createABiTree();
// question1
	preOrder(t);
	cout<<endl;
	inOrder(t);
	cout<<endl;
	postOrder(t);
	cout<<endl;
	levelOrder(t);
	cout<<endl;
	cout<<"height is "<<heightOfT(t)<<endl;
// question2
	// int pre[] = {500,64,25,0,37,37,37,26,59,328,74,115,97,92,86,106,109,261,214,212,151,213,226,221,254,240,275,263,312,468,353,337,351,393,355,362,460,444,441,427,412,396,427,439,459,453,496,490,476,635,542,540,529,514,540,532,580,574,559,553,544,574,630,638,751,673,648,665,660,745,732,692,690,678,707,989,970,828,778,773,774,779,791,790,816,815,822,908,860,852,856,862,867,904,942,928,937,972,974,976};
	// int in[]  = {0,25,26,37,37,37,59,64,74,86,92,97,106,109,115,151,212,213,214,221,226,240,254,261,263,275,312,328,337,351,353,355,362,393,396,412,427,427,439,441,444,453,459,460,468,476,490,496,500,514,529,532,540,540,542,544,553,559,574,574,580,630,635,638,648,660,665,673,678,690,692,707,732,745,751,773,774,778,779,790,791,815,816,822,828,852,856,860,862,867,904,908,928,937,942,970,972,974,976,989};
	// BiTree tt = createTwithPreIn(pre, in, 0, 99, 0, 99);
	// preOrder(tt);
	// postOrderNoRecurve(t);

// question3
	initUFSets();
	srand(time(NULL));
	for (int i = 0; i < 100; ++i)
	{
		printf("%d ", rand() % 100);
		Union(rand() % 100, rand() % 100);
	}

	for (int i = 0; i < 100; ++i)
	{
		printf("find(%d) = %d\n", i, Find(i));
	}

	return 0;
}