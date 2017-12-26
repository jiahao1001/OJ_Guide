#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
#include<set>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		cin>>n;
		set<int> removal;
		multiset<int> all;
		int x;
		for(int i=0;i<n;i++) cin>>x,removal.insert(x);
		int p = 1;
		char cmd;
		int cnt = 0;
		while(cin>>cmd,cmd!='e'){
			if(cmd=='a') cin>>x, all.insert(x);
			else if(cmd=='p') cin>>x, p=x;
			else{
				cnt++;
				int r = 0;
				if(all.size()==0) continue;
				if(p==1){
					r = *all.begin();
					all.erase(all.begin());
				}else{
					r = *(--all.end());
					all.erase(--all.end());
				}
				if(removal.count(cnt)) printf("%d\n",r);
			}
		}
        printf("\n");
	}
	return 0;
}
