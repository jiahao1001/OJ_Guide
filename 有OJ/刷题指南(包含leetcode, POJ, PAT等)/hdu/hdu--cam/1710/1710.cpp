#include<iostream>

using namespace std;
int pre [1002], mid[1002];
void Postprint(int start1, int start2, int size, bool flag){
	if(size == 1){
		printf("%d ", pre[start1]);
		return;
	}else if(size <= 0)
	return;
	int i;
	for(i = 0; i < size && pre[start1] != mid[start2+i]; i++);
	Postprint(start1+1, start2, i, false);
	Postprint(start1+i+1, start2+i+1, size-i-1, false);
	if(flag)
		printf("%d/n",  pre[start1]);
	else 
		printf("%d ", pre[start1]);
}
int main(){
	freopen("1710.in", "r", stdin);
	freopen("1710.out", "w", stdout);
	int n, i;
	while(~scanf("%d", &n)){
		for(i = 0; i < n; i++)
			scanf("%d", &pre[i]);
		for(i = 0; i < n; i++)
			scanf("%d", &mid[i]);
		Postprint(0, 0, n, true);
	}
	return 0;
}
