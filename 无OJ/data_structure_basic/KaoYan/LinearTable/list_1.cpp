/* 
 * 1.从顺序表中删除具有最小值的元素并由函数返回被删除元素的值，空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并推出运行。
 * 2.设计一个高效的算法，将顺序表的所有元素逆置,要求空间复杂度为O(1)
 * 3.长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素。
 * 4.从有序顺序表中删除其值在给定值s与t之间(要求s<t)的所有元素，如果s或t不合理或者顺序表为空则显示出错信息并退出运行。
 * 5.从顺序表中删除所有值重复的元素。
 * 6.将两个有序表合并成一个新的有序表，并由函数返回结果顺序表。
 * 7.已知在一维数组A[m+n]中一次存放着两个线性表(a1,a2,...,am)和(b1,b2,...,bn)。试编写一个函数，将数组中两个顺序表的位置互换。
 * 8.顺序表，设计一个算法完成用最少的时间在表中查找到数值为x的元素，若找到将其与后继元素位置互换，若找不到将其插入表中且仍使其递增序。
 * 9.给出一个在时间和空间上都很高效的算法求得两个升序序列的中位数。
 * 10.求主元(元素个数m > n/2)。
 * 11.基数排序
 */
#include "list_1.h"
#include <math.h>
#include <Queue>

// question1
bool deleteMin(sqList &L, elementType &e)
{
	if (L.length == 0) // 顺序表长度为0，返回错误
		return false;
	e = L.element[0];
	int j = 0;
	for (int i = 1; i < L.length; ++i) {
		if (L.element[i] < e) {
			e = L.element[i];
			j = i;
		}
	}
	L.element[j] = L.element[L.length - 1]; // 替换最小元素
	L.length --;
	return true;
}

// question2
void reverseElement(sqList &L)
{
	int temp;
	// 前面元素与后面元素互换
	for (int i = 0; i < L.length / 2; ++i) {
		temp = L.element[i];
		L.element[i] = L.element[L.length - 1 - i]; 
		L.element[L.length - 1 - i] = temp;
	}
}
// question3
void deleteAllX(sqList &L, elementType x)
{
	int k = 0;
	for (int i = 0; i < L.length; ++i) {
		// 不是x时,将元素移到之前都不是x元素的地方
		if (L.element[i] != x) {
			L.element[k] = L.element[i];
			k ++;
		}
	}
	L.length = k;
}
// question4
bool deleteST(sqList &L, int s, int t)
{
	// 检查输入值的合法性
	if (s > t || L.length == 0)
		return false;
	int len = L.length;
	int k = 0;
	for (int i = 0; i < len; ++i) {
		// 符合的元素放入前面都符合的地方存储
		if (s > L.element[i] || t < L.element[i]) {
			L.element[k] = L.element[i];
			k ++;
		}
	}
	L.length = k;
	return true;
}
// question5
int cmpSort(const void *a, const void*b)
{
	return *((int *)a) > *((int *)b) ? 1 : -1;
}
bool deleteMul(sqList &L)
{
	if (L.length == 0)
		return false;
	// 快速排序
	qsort(L.element, L.length, sizeof(elementType), cmpSort); 
	int j = 0;
	for (int i = 1; i < L.length; ++i) {
		if (L.element[j] != L.element[i])
			L.element[++j] = L.element[i];
	}
	L.length = j + 1;
	return true;
}
// question6
sqList mergeAB(sqList A, sqList B)
{
	sqList result;
	result.length = -1;
	if ((A.length + B.length) > MAXSIZE)
		return result;
	int i = 0, j = 0, k = 0;
	result.length = A.length + B.length;
	// 将A与B依序比较，存入顺序表
	while(j < A.length && k < B.length) {
		if (A.element[j] <= B.element[k])
			result.element[i ++] = A.element[j ++];
		else
			result.element[i ++] = B.element[k ++];
	}
	// 当A的某一个元素大于B的最大值时，将A剩下所有的元素放入顺序表，以下对B同理
	while(j < A.length)
		result.element[i ++] = A.element[j ++];
	while(k < B.length)
		result.element[i ++] = A.element[k ++];
	return result;
}
// question7
void reverse(int A[], int left, int right)
{
	int temp;
	for (int i = 0; i < (right - left +1)/2; ++i) {
		temp = A[left + i];
		A[left + i] = A[right - i];
		A[right - i] = temp; 
	}
}
void changeMN(int R[], int n, int p)
{
	reverse(R, 0, p - 1);
	reverse(R, p, n-1);
	reverse(R, 0, n-1);
}
// question8
void binarySearchAndInsert(sqList &L, int element)
{
	qsort(L.element, L.length, sizeof(elementType), cmpSort);
	deleteMul(L);
	int low = 0, high = L.length - 1, mid;
	// 二叉查找
	while (low <= high) {
		mid = (low + high)/2;
		if (L.element[mid] == element)
			break;
		else if (L.element[mid] < element)
			low = mid + 1;
		else
			high = mid - 1;
	}
	// 如果不是最后一个元素，就执行后继交换
	if (L.element[mid] == element && mid != (L.length - 1)) {
		int t = L.element[mid];
		L.element[mid] = L.element[mid + 1];
		L.element[mid + 1] = t;
	}
	// 查找失败，插入数据
	if (low > high) {
		for (int i = L.length - 1; i > high; --i)
			L.element[i + 1] = L.element[i];
		L.element[high + 1] = element;
	}
}
// question9
int medianNumOfAB(sqList A, sqList B)
{
	int a_left = 0, a_right = A.length - 1, b_left = 0, b_right = B.length - 1;
	int a_mid, b_mid; 
	// A或B 的元素没有检索完全
	while(a_left != a_right || b_left != b_right) {
		a_mid = (a_left + a_right) / 2;
		b_mid = (b_left + b_right) / 2;
		// 中位数相等时，返回找到中位数
		if (A.element[a_mid] == B.element[b_mid])
			return A.element[a_mid];
		// 中位数A < B,则中位数在A的后半部分或B的前半部分
		if (A.element[a_mid] < B.element[b_mid]) {
			// 个数为偶数
			if ((a_left + a_right) % 2 == 0) {
				a_left = a_mid;
				b_right = b_mid;
			}
			else {
				a_left = a_mid + 1;
				b_right = b_mid;
			}
		}
		// 中位数A > B,则中位数在A的前半部分或B的后半部分
		else {
			if ((b_left + b_right) % 2 == 0) {
				a_right = a_mid;
				b_left = b_mid;
			}
			else {
				a_right = a_mid;
				b_left = b_mid + 1;
			}
		}
	}
	return A.element[a_left] > B.element[b_left] ? A.element[a_left] : B.element[b_left];
}
// question10
int majority(sqList L)
{
	int c, count = 1; // c用来保存候选主元,count计数
	c = L.element[0];
	for (int i = 1; i < L.length; ++i) {
		if (L.element[i] == c)
			count ++; // 候选主元计数
		else {
			if (count > 0)
				count --; // 不是候选主元时
			else {		  // 更换候选主元
				c = L.element[i];
				count = 1;
			}
		}
		printf("%d %d\n", count, c);
	}
	if (count > 0)
	{
		for (int i = count = 0; i < L.length; ++i) {
			if (L.element[i] == c)
				count ++;
		}
	}
	if (count > L.length / 2)
		return c;
	return -1;
}

void printList(sqList &L)
{
	for (int i = 0; i < L.length; ++i)
		printf("%d ", L.element[i]);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	FILE *f = fopen("nums.data", "r");
	sqList L;
	L.length = 0;
	int num = 0;
	for (int i = 0; i < 100 - 1; ++i) {
		num = getw(f);
		L.element[i] = num;
		L.length ++;
	}
	fclose(f);
// quesion 6
	// qsort(L.element, L.length, sizeof(elementType), cmpSort);
	// sqList A,B;
	// int j = 0;
	// int k = 0;
	// for (int i = 0; i < L.length; ++i) {
	// 	if (i % 2)
	// 		A.element[j ++] = L.element[i];
	// 	else
	// 		B.element[k ++] = L.element[i];
	// }
	// A.length = j; B.length = k;
	// sqList r = mergeAB(A, B);
	// printf("%d %d %d\n", A.length, B.length, r.length);
	// printList(r);
	// printList(L);
	// changeMN(L.element, L.length, L.length / 2);
	// printList(L);
// question 8
	// binarySearchAndInsert(L, 106);
	// printList(L);
	// binarySearchAndInsert(L, 100);
	// printList(L);
	// binarySearchAndInsert(L, 37);
	// printList(L);
// question 9
	// qsort(L.element, L.length, sizeof(elementType), cmpSort);
	// sqList A,B;
	// int j = 0;
	// int k = 0;
	// for (int i = 0; i < L.length; ++i) {
	// 	if (i % 2)
	// 		A.element[j ++] = L.element[i];
	// 	else
	// 		B.element[k ++] = L.element[i];
	// }
	// A.length = j; B.length = k;
	// printList(A);
	// printList(B);
	// printf("%d\n", medianNumOfAB(B, A));

// question 10
	// sqList A;
	// for (int i = 0; i < 20; ++i)
	// {
	// 	if (i < 2)
	// 		A.element[i] = 1;
	// 	else if (i % 4 == 0)
	// 		A.element[i] = 2;
	// 	else
	// 		A.element[i] = 10;
	// 	A.length ++;
	// }
	// printf("%d\n", majority(A));
// question11
	std::queue<int> numQueue[10];
	for (int i = 0, k = 0; k < 3; ++i) {
		int n = ((int)(L.element[i] / (pow(10,k)))) % 10;
		numQueue[n].push(L.element[i]);
		if (i >= L.length - 1) {
			k ++; i = 0;
			for (int m = 0, j = 0; m < 10; ++m) {
				while(!numQueue[m].empty()){
					L.element[j ++] = numQueue[m].front();
					numQueue[m].pop();
				}
			}
		}
	}
	printList(L);
	
	return 0;
}

