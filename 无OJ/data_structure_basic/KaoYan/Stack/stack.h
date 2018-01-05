#include <iostream>
using namespace std;

#ifndef MaxSize
#define MaxSize 100
#endif
// 顺序栈
typedef struct SNode {
	int data[MaxSize];
	int top;
} SqStack;

bool isEmpty(SqStack s) {
	return s.top == -1;
}

bool isFull(SqStack s) {
	return (s.top >= MaxSize - 1);
}

void initStack(SqStack &s) {
	s.top = -1;
}

void push(SqStack &s,int e) {
	s.data[++ s.top] = e;
}

int pop(SqStack &s) {
	return s.data[s.top --];
}

int getTop(SqStack s) {
	if (isEmpty(s)) {
		return -1;
	}
	return s.data[s.top];
}

int getSize(SqStack s) {
	return s.top;
}