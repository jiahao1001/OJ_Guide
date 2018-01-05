/* 链表实现线性表
 * 1.删除不带头和带头结点的单链表L中所有值为x的结点。
 * 2.设L为带头结点的单链表，编写算法实现从尾到头反向输出每个节点的值。
 * 3.删除最小值。
 * 4.编写O(1)空间复杂度的算法，将带头结点的链表逆置。
 * 5.使链表递增有序。
 * 6.将一个表间隔一个节点分成两个表A，B；按增序打印A,B链表元素，并删除每次打印出来的最小元素。
 * 7.将A和B两个单链表中的公共元素合并生成C，要求不破坏A,B结点。
 * 8.查找带头结点单链表的倒数第k个节点，如果存在返回1，反之返回0。
 * 9.非循环双链表，头指针为L，除了data,pre,next外，还有一个访问频度freq(初始化时为0),
 * locate(L,x)使元素值为x的freq+1,并使其按非增序排列,函数返回找到的节点地址。
 */

#include "linkList.h"
// question1
void deleteAllX(LinkList &L, int x)
{
	LNode *p;
	// 为空返回
	if (L == NULL)
		return;
	// 结点等于x时，递归删掉头结点
	if (L->data == x) {
		p = L;
		L = L->next;
		free(p);
		deleteAllX(L, x);
	} else {
		deleteAllX(L->next, x);
	}
}
// 非递归函数
void deleteAllXNotRecursion(LinkList &L, int x)
{
	LNode *p;
	// 去掉头结点 = x的结点。
	while(L->data == x && L != NULL) {
		p = L;
		L = L->next;
		free(p);
	}
	LNode *temp = L;
	while(temp->next != NULL) {
		p = temp->next;
		// 相等时，删掉结点
		if (p->data == x) {
			temp->next = p->next;
			free(p);
		}
		else
			temp = temp->next;
	}
}
// question2 递归算法
void printReverse(LinkList L)
{
	if (L->next != NULL)
		printReverse(L->next);
	printf("%d ", L->data);
}
// question3
void deleteMin(LinkList &L)
{
	// pre存储当前位置的前趋指针
	LNode *pre = L, *p = L->next, *minpre = pre, *min = p;
	while(p != NULL) {
		if (p->data < min->data) {
			min = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	minpre->next = min->next;
	free(min);
}
// question4
// 方法一：采用头插法重新生成整个链表
void reverseList(LinkList &L)
{
	LNode *p = L->next, *temp;
	L->next = NULL;
	while(p != NULL) {
		temp = p->next;
		p->next = L->next;
		L->next = p;
		p = temp;
	}
}
// 方法二：改写指针，将结点指针反转
void reverseList2(LinkList &L)
{
	LNode *pre, *p = L->next, *pnext = p->next;
	p->next = NULL;
	while(pnext != NULL) {
		pre = p;
		p = pnext;
		pnext = pnext->next; 
		p->next = pre; //指针反转
	}
	L->next = p;
}
// question5
void sortInc(LinkList &L)
{
	// 插入排序，p存放当前的结点，pre存放p前一个结点，rear存放p后的一个结点
	LNode *p = L->next, *pre, *rear = p->next;
	// 生成一个单节点有序表
	p->next = NULL;
	p = rear;
	// 遍历剩下的表
	while(p != NULL)
	{
		rear = p->next;
		pre = L;
		while(pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = rear;
	}
}
// question6
void deleteAllMin(LinkList l)
{
	LNode *pre, *p, *rear;
	while(l->next != NULL) {
		pre = l;
		p = pre->next;
		while(p->next != NULL) {
			if (p->next->data < pre->next->data)
				pre = p;
			p = p->next;
		}
		printf("%d ", pre->next->data);
		rear = pre->next;
		pre->next = rear->next;
		free(rear);
	}
	free(l);
}
// question7
LinkList get_common(LinkList l1, LinkList l2)
{
	LinkList result = (LinkList)malloc(sizeof(LNode));
	LNode *pa = l1->next, *pb = l2->next, *t = result, *s;
	while(pa != NULL && pb != NULL) {
		if (pa->data < pb->data)
			pa = pa->next;
		else if (pa->data > pb->data)
			pb = pb->next;
		else {
			s = (LNode *)malloc(sizeof(LNode));
			s->data = pa->data;
			t->next = s; t = s; // 尾插法
			pa = pa->next;
			pb = pb->next;
		}
	}
	t->next = NULL;
	return result;
}
// question8
bool findK(LinkList l, int k)
{
	// 两个节点，先让一个向前遍历k次，然后两个同步遍历，直到最后一个节点
	LNode *p = l->next, *q = l->next;
	int count = 0;
	while(p != NULL) {
		if (count < k) 
			count ++;
		else
			q = q->next; // 只有count == k时，才让两个指针同步移动
		p = p->next;
	}
	// printf("count = %d\n", count);
	if (count < k)
		return 0;
	printf("The %dth is %d\n", k,q->data);
	return 1;
}
// question9
DoubleList locate(DoubleList d, int x)
{
	DoubleNode *p = d->next;
	while (p && p->data != x) 
		p = p->next;
	if (!p) {
		// printf("cannot find a node which data is = %d\n", x);
		return NULL;
	}
	p->freq ++;
	// 使p节点变成一个自由节点
	if (p->next != NULL)
		p->next->pre = p->pre;
	p->pre->next = p->next;

	// 查找到p的插入位置

	DoubleNode *q = p->pre;
	while( (q != d) && (q->freq <= p->freq)){
		q = q->pre;
	}
	// 插入p节点
	p->next = q->next;
	q->next->pre = p;
	p->pre = q;
	q->next = p;

	return p;
}

int main(int argc, char const *argv[])
{
	LinkList list = createLinkList();
	printLinkList(list);
// question1
	// LinkList s = list->next; // 去掉头结点
	// free(list);
	// deleteAllX(s, 64);
	// printf("%d ", s->data);
	// printLinkList(s);
	// deleteAllXNotRecursion(s, 514);
	// printf("%d ", s->data);
	// printLinkList(s);
// question2
	// printReverse(list->next);
// question3
	// deleteMin(list);
	// printLinkList(list);
// question4
	// reverseList(list);
	// printLinkList(list);
	// reverseList2(list);
	// printLinkList(list);
// question5
	// sortInc(list);
	// printLinkList(list);
// question6
	// LinkList l1 = (LNode *)malloc(sizeof(LNode)), l2 = (LNode *)malloc(sizeof(LNode));
	// LNode *pre = list->next, *rear, *temp;
	// int i = 0;
	// while(pre != NULL){
	// 	rear = pre->next;
	// 	if ( i % 2 == 0) {
	// 		temp = l1->next;
	// 		l1->next = pre;
	// 		l1->data ++; //记录个数
	// 		pre->next = temp;
	// 	} else {
	// 		temp = l2->next;
	// 		l2->next = pre;
	// 		l2->data ++; //记录个数
	// 		pre->next = temp;
	// 	}
	// 	pre = rear;
	// 	i ++;
	// }
	// deleteAllMin(l1);
	// printf("\n");
	// deleteAllMin(l2);
// question7
	// sortInc(l1);
	// sortInc(l2);
	// LinkList q7 = get_common(l1, l2);
	// printLinkList(q7);
// question8
	// findK(l1, 20);
// question9
	DoubleList d = createDoubleList();
	printDoubleList(d);
	for (int i = 0; i < 10000; ++i)
	{
		locate(d, rand() % 1000);
	}
	printDoubleFreq(d);
	printDoubleList(d);


	return 0;
}