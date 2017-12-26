#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
string ns = "23456789TJQKA";
string cs = "CDSH";
struct Card{
	char N,C;
} adam[26],eva[26];
bool operator<(const Card &c1, const Card &c2){
	if(c1.N==c2.N) return cs.find(c1.C) < cs.find(c2.C);
	return ns.find(c1.N)<ns.find(c2.N);
}

int t,k;
int main(){
	scanf("%d",&t);
	char cc[10];
	while(t--){
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			scanf("%s",cc);
			adam[i].N = cc[0];
			adam[i].C = cc[1];
		}
		for(int i=0;i<k;i++){
			scanf("%s",cc);
			eva[i].N = cc[0];
			eva[i].C = cc[1];
		}
		sort(adam,adam+k);
		sort(eva,eva+k);
		int p = 0;
		for(int i=0,j=0;i<k && j<k;i++){
			while(j<k && eva[j]<adam[i]) j++;
			if(j!=k)p++,j++;
		}
		printf("%d\n",p);
	}
	return 0;
}
