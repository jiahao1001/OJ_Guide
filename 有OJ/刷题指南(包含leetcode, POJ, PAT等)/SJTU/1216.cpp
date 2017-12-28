#include <cstdio>
class priorityQueue
{
private:
	int size, capacity;
	int *array;
public:
	priorityQueue(int c) :capacity(c), size(0)
	{
		array = new int[capacity + 1];
	}
	~priorityQueue() { delete[] array; }
	void enQueue(int x);
	int find(int x);
	void decrease(int pos, int amount);
};
void priorityQueue::decrease(int pos, int amount)
{
	int x, hole = pos;
	for (x = array[pos] - amount; hole>1 && x<array[hole / 2]; hole /= 2) array[hole] = array[hole / 2];
	array[hole] = x;
}
int priorityQueue::find(int x)
{
	int t = -1;
	for (int i = 1; i <= size; ++i) if ((array[i]>x) && (t == -1 || array[i]<array[t])) t = i;
	return t;
}
void priorityQueue::enQueue(int x)
{
	int hole = ++size;
	for (; hole>1 && x<array[hole / 2]; hole /= 2) array[hole] = array[hole / 2];
	array[hole] = x;
}
int main()
{
	//freopen("1216.in","r",stdin);
	int m, i, t, y;
	char s[10];
	scanf("%d", &m);
	priorityQueue pq(m);
	for (i = 0; i<m; ++i)
	{
		scanf("%s", s);
		scanf("%d", &t);
		if (s[0] == 'i') pq.enQueue(t);
		else if (s[0] == 'f') printf("%d\n", pq.find(t));
		else
		{
			scanf("%d", &y);
			pq.decrease(t, y);
		}
	}
}
