#include <iostream>
using namespace std;
class Set
{
private:
	int data[10000];
	int size;
public:
	Set() :size(0) {}
	Set(const Set& other) :size(other.size)
	{
		for (int i = 0; i<size; ++i) data[i] = other.data[i];
	}
	Set& operator=(const Set& other)
	{
		if (this == &other) return (*this);
		size = other.size;
		for (int i = 0; i<size; ++i) data[i] = other.data[i];
		return (*this);
	}
	Set& operator*=(const Set& other);
	void insert(int value);
	int b_search(int value);
	int bb_search(int value);
	void remove(int value);
	friend ostream& operator<<(ostream& out, const Set& s);
};
int Set::b_search(int value)
{
	int l = 0, r = size - 1, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (data[mid] == value) return mid;
		if (data[mid]<value) l = mid + 1; else r = mid - 1;
	}
	return -1;
}
void Set::insert(int value)
{
	if (b_search(value) == -1)
	{
		int pos = bb_search(value), i;
		for (i = size; i>pos; --i) data[i] = data[i - 1];
		data[pos] = value;
		++size;
	}
}
int Set::bb_search(int value)
{
	int l = 0;
	while (l<size && data[l]<value) ++l;
	return l;
}
void Set::remove(int value)
{
	int pos = b_search(value);
	if (pos != -1)
	{
		int i;
		--size;
		for (i = pos; i<size; ++i) data[i] = data[i + 1];
	}
}
ostream& operator<<(ostream& out, const Set& s)
{
	for (int i = 0; i<s.size; ++i) out << s.data[i] << ' ';
	out << '\n';
	return out;
}
Set& Set::operator*=(const Set& other)
{
	Set tmp;
	for (int i = 0; i<other.size; ++i) if (b_search(other.data[i]) != -1) tmp.insert(other.data[i]);
	(*this) = tmp;
	return *this;
}
int main()
{
	int n, i, t, m, j;
	Set ss;
	char f;
	cin >> n;
	for (i = 0; i<n; ++i)
	{
		cin >> f;
		if (f == '+')
		{
			cin >> m;
			for (j = 0; j<m; ++j)
			{
				cin >> t;
				ss.insert(t);
			}
		}
		else if (f == '-')
		{
			cin >> m;
			for (j = 0; j<m; ++j)
			{
				cin >> t;
				ss.remove(t);
			}
		}
		else
		{
			Set tp;
			cin >> m;
			for (j = 0; j<m; ++j)
			{
				cin >> t;
				tp.insert(t);
			}
			ss *= tp;
		}
		cout << ss;
	}
}
