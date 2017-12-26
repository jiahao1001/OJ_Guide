#include<stdio.h>
#include<string>
#include<iostream>
#include<ctype.h>
using namespace std;
int main()
{
	char str[101];
	gets(str);
	string a = str;
	for (int i = 0; i < a.size(); i++)
	{
		a[i] = tolower(a[i]);
	}
	while (gets(str))
	{
		string b = str, c = b;
		for (int i = 0; i < b.size(); i++)
		{
			b[i] = tolower(b[i]);
		}
		int t = b.find(a, 0);
		while (t != string::npos)
		{
			c.erase(t, a.size());
			b.erase(t, a.size());
			t = b.find(a, t);
		}
		t = c.find(' ', 0);
		while (t!=string::npos)
		{
			c.erase(t, 1);
			t = c.find(' ', 0);
		}
		cout << c << endl;
	}
	return 0;
}