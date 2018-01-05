/* 1.用两个栈模拟一个队列
 *
 */
#include "stack.h"

void enQueue(SqStack &s1, SqStack &s2, int e) {
	if (isFull(s1)) {
		cout<<"Queue is full"<<endl;
		return ;
	}
	while(!isEmpty(s2)) {
		push(s1, pop(s2));
	}
	push(s1, e);

}

int deQueue(SqStack &s1, SqStack &s2) {
	if (isEmpty(s1) && isEmpty(s2)) {
		cout<<"Queue is empty"<<endl;
		return -1;
	}
	while(!isEmpty(s1)) {
		push(s2, pop(s1));
	}
	return pop(s2);
}

// question2
int fun(int n, int x) {
	struct stack {
		int n;
		int result;
	} st[100];
	int top = -1;
	int f1 = 1, f2 = 2 * x;
	if (n == 0) 
		return f1;
	if (n == 1)
		return f2;
	for (int i = n; i >= 2; --i) {
		st[++top].n = i;
	}
	while(top >= 0) {
		st[top].result = 2 * x * f2 - 2 * (st[top].n - 1)*f1;
		f1 = f2;
		f2 = st[top].result;
		top --;
	}
	return f2;
}
int main(int argc, char const *argv[])
{
	SqStack s1, s2;
	initStack(s1);initStack(s2);

	for (int i = 0; i < 100; ++i) {
		enQueue(s1, s2, i);
	}
	for (int i = 0; i < 100; ++i) {
		cout<<deQueue(s1, s2)<<" ";
	}
	cout<<endl<<fun(10,11)<<endl;
	return 0;
}