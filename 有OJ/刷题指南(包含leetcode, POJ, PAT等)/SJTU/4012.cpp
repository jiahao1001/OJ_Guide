#include <cstdio>
class priorityQueue
{
private:
	int size, capacity;
	int *array;
	void percolateDown(int hole);
public:
	void buildHeap();
	priorityQueue(int c) :capacity(c), size(0)
	{
		array = new int[capacity + 1];
	}
	~priorityQueue() { delete[] array; }
	bool isEmpty() { return (size == 0); }
	void enQueue(int x);
	int deQueue();
};
void priorityQueue::enQueue(int x)
{
	int hole = ++size;
	for (; hole>1 && x<array[hole / 2]; hole /= 2) array[hole] = array[hole / 2];
	array[hole] = x;
}
void priorityQueue::percolateDown(int hole)
{
	int child, tmp = array[hole];
	for (; hole * 2 <= size; hole = child)
	{
		child = hole * 2;
		if (child != size && array[child + 1]<array[child]) ++child;
		if (array[child]<tmp) array[hole] = array[child]; else break;
	}
	array[hole] = tmp;
}
int priorityQueue::deQueue()
{
	int mi = array[1];;
	array[1] = array[size--];
	percolateDown(1);
	return mi;
}
void priorityQueue::buildHeap()
{
	int i;
	for (i = 1; i <= capacity; ++i) scanf("%d", &array[i]);
	size = capacity;
	for (i = size / 2; i>0; --i) percolateDown(i);
}
int main()
{
	int n;
	scanf("%d", &n);
	priorityQueue pq(n);
	pq.buildHeap();
	long long res = 0;
	int x, y;
	if (n <= 1)
	{
		printf("0");
		return 0;
	}
	while (true)
	{
		x = pq.deQueue();
		y = pq.deQueue();
		res += x + y;
		if (pq.isEmpty()) break;
		pq.enQueue(x + y);
	}
	printf("%lld", res);
}
