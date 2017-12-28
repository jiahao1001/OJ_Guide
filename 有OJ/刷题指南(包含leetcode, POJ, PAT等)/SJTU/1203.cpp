#include <iostream>
using namespace std;
template <class T> class seqList;
template <class T> istream& operator >> (istream& in, seqList<T>& v);
template <class T> ostream& operator<< (ostream& out, const seqList<T>& v);
template <class T> seqList<T> operator+ (const seqList<T>& v1, const seqList<T>& v2);
template <class T>
class seqList
{
private:
	int length;
	T* data;
public:
	seqList(int n = 0) :length(n) { if (n>0) data = new T[n]; }
	seqList(const seqList<T>& v);
	seqList& operator=(const seqList& v);
	friend istream& operator >> <>(istream& in, seqList<T>& v);
	friend ostream& operator<< <>(ostream& out, const seqList<T>& v);
	friend seqList<T> operator+ <>(const seqList<T>& v1, const seqList<T>& v2);
	~seqList() { if (length>0) delete[] data; }
};
template <class T>
seqList<T>::seqList(const seqList<T>& v)
{
	length = v.length;
	delete[] data;
	data = new T[length];
	for (int i = 0; i<length; ++i) data[i] = v.data[i];
}
template <class T>
seqList<T>& seqList<T>::operator=(const seqList<T>& v)
{
	if (this == &v) return (*this);
	length = v.length;
	delete[] data;
	data = new T[length];
	for (int i = 0; i<length; ++i) data[i] = v.data[i];
	return (*this);
}
template <class T> istream& operator >> (istream& in, seqList<T>& v)
{
	for (int i = 0; i<v.length; ++i) in >> v.data[i];
	return in;
}
template <class T> ostream& operator<< (ostream& out, const seqList<T>& v)
{
	for (int i = 0; i<v.length; ++i) out << v.data[i] << ' ';
	return out;
}
template <class T>
seqList<T> operator+(const seqList<T>& v1, const seqList<T>& v2)
{
	seqList<T> tmp(v1.length + v2.length);
	int i;
	for (i = 0; i<v1.length; ++i) tmp.data[i] = v1.data[i];
	for (i = 0; i<v2.length; ++i) tmp.data[i + v1.length] = v2.data[i];
	return tmp;
}
int main()
{
	int a, b; char typ[10];
	cin >> typ;
	cin >> a >> b;
	if (typ[0] == 'i')
	{
		seqList<int> v1(a), v2(b);
		cin >> v1 >> v2;
		cout << v1 + v2;
	}
	else if (typ[0] == 'c')
	{
		seqList<char> v1(a), v2(b);
		cin >> v1 >> v2;
		cout << v1 + v2;
	}
	else if (typ[0] == 'd')
	{
		seqList<double> v1(a), v2(b);
		cin >> v1 >> v2;
		cout << v1 + v2;
	}
}
