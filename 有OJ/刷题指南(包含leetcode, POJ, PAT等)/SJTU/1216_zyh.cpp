#include <iostream>

using namespace std;

int N;
int a, b;
char cmd[10] = { 0 };


template <class T>
class PriorityQueue
{
public:
	PriorityQueue(int capacity = 100)
	{
		array = new T[capacity];
		maxSize = capacity;
		currentSize = 0;
	}
	PriorityQueue(const T data[], int size);
	~PriorityQueue() { delete[] array; }

	bool isEmpty()const { return currentSize == 0; }
	void enQueue(const T& x);
	T deQueue();
	T getHead() const { return array[1]; }

	int findMin(T x)
	{
		int r = -1;
		for (int i = 1; i <= currentSize; i++)
		{
			if (array[i] > x)
			{
				if (r == -1)
				{
					r = i;
				}
				else if (array[i] < array[r])
				{
					r = i;
				}
			}
		}
		return r;
	}

	void decreaseKey(int i, T value)
	{
		T x;
		int hole = i;

		array[hole] -= value;
		for (x = array[i]; hole > 1 && x < array[hole / 2]; hole /= 2)
		{
			array[hole] = array[hole / 2];
		}
		array[hole] = x;
	}

private:
	int currentSize;
	T* array;
	int maxSize;

	void doubleSpace();
	void buildHeap();
	void percolateDown(int hole);
};

template <class T>
void PriorityQueue<T>::enQueue(const T& x)
{
	if (currentSize == maxSize - 1)
	{
		doubleSpace();
	}

	//ÏòÉÏ¹ýÂË
	int hole = ++currentSize;
	for (; hole > 1 && x < array[hole / 2]; hole /= 2)
	{
		array[hole] = array[hole / 2];
	}
	array[hole] = x;
}

template <class T>
T PriorityQueue<T>::deQueue()
{
	T minItem;
	minItem = array[1];
	array[1] = array[currentSize--];
	percolateDown(1);
	return minItem;
}

template <class T>
void PriorityQueue<T>::percolateDown(int hole)
{
	int child;
	T tmp = array[hole];

	for (; hole * 2 <= currentSize; hole = child)
	{
		child = hole * 2;
		if (child != currentSize && array[child + 1] < array[child])
		{
			child++;
		}
		if (array[child] < tmp)
		{
			array[hole] = array[child];
		}
		else
		{
			break;
		}
	}
	array[hole] = tmp;
}

template <class T>
void PriorityQueue<T>::buildHeap()
{
	for (int i = currentSize / 2; i > 0; i--)
	{
		percolateDown(i);
	}
}

template <class T>
PriorityQueue<T>::PriorityQueue(const T data[], int size)
{
	maxSize = size + 10;
	currentSize = size;
	array = new T[maxSize];
	for (int i = 0; i < size; i++)
	{
		array[i + 1] = data[i];
		buildHeap();
	}
}

template <class T>
void PriorityQueue<T>::doubleSpace()
{
	T* tmp = array;

	maxSize *= 2;
	array = new T[maxSize];

	for (int i = 0; i <= currentSize; i++)
	{
		array[i] = tmp[i];
	}
	delete[] tmp;
}

int main()
{
	PriorityQueue<int> PQ;
	cin >> N;
	cin.get();
	for (int i = 0; i < N; i++)
	{
		cin.getline(cmd,10,' ');
		switch (cmd[0])
		{
		case 'i':cin >> a;
			PQ.enQueue(a);
			break;
		case 'f':cin >> a;
			cout << PQ.findMin(a) << "\n";
			break;
		case 'd':cin >> a >> b;
			PQ.decreaseKey(a, b);
			break;
		}
		cin.get();
	}
	system("pause");
}