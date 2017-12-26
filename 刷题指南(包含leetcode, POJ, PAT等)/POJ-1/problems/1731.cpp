#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	cout<<s<<endl;
	while(next_permutation(s.begin(),s.end())) {
		cout<<s<<endl;
	}
	return 0;
}
