#include <bits/stdc++.h>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
using namespace std;

int sta[12],curr,trie[6000000][2],trie_;
bool arr[20001];


void push_trie(int flag,int people){
	F(people+1)arr[i]=1;                //[1] ~ [people]
	Fl(i,1,flag+1)
		for(int j=sta[i];j<=people;j+=sta[i])
			arr[j]=!arr[j];
	curr=0;
	Fl(i,1,people+1){
		if(trie[curr][arr[i]] == 0 ){
            trie[curr][arr[i]] = ++trie_;
            memset(trie[trie_],0,sizeof(trie[trie_]));
		}
		curr = trie[curr][arr[i]];
	}
}

/*void dfs(int flag,int K,int R,int P){		//K=enum_MAX R=round_MAX
	Fl(i,sta[flag-1]+1,K+1){                //sta[] save K
		sta[flag]=i;                        //from the front value add 1 to K's max
		if((flag&1) == (R&1)){
			push_trie(flag,P);
		}
		if(R>flag && sta[flag]<K)           //if have next round and next value
			dfs(flag+1,K,R,P);              //fill the next one in sta[]
	}
}*/

void pickK(int people, int K, int round){
    for(int i=0,total;i<(1<<K);i++){
        total=0;
        for(int j=0;j<K;j++)
            if((1<<j) & i)total++;
        if(total > round || (total-round)&1 )
            continue;
        total=0;
        for(int j=0;j<K;j++)if((1<<j) & i)sta[++total]=j+1;
        push_trie(total,people);
    }
}

void show_trie(int flag, int now){	//flag = now, which step
	bool leaf=1;
	F(2){
		if(trie[now][i]){
			leaf=0;
			arr[flag]=i;			//record from trie[1] to leaf
			show_trie(flag+1,trie[now][i]);
		}
	}
	if(leaf){
		Fl(i,1,flag)printf("%d",(int)arr[i]);
		printf("\n");
	}
}

int main(){
#ifdef local
	freopen("57.in","r",stdin);
#endif
	int P,N,M,first=1;
	//P=people N=Max_K M=round
	while(scanf("%d %d %d",&P,&N,&M)==3 && ( P || N || M )){	//if(M is even)puts 11..
        if(first)first=0;
        else printf("\n");
        memset(trie[0],0,sizeof(trie[0]));
        trie_=0;
		pickK(P,N,M);
		show_trie(1,0);
	}
}
//save all solutions in trie
//the numbers of k need to pick are M,M-2,M-4,...,0 or 1
//enum N from 1
