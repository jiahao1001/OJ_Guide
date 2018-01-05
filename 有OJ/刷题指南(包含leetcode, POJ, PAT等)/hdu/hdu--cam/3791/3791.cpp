#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>

const int max = 1025;
char tra[max],trb[max],seq[11];
bool Insert(char tr[],char c){
	int st = 1;
	bool mark = true;
	while(1){
		if(tr[st] == 0){
			tr[st] = c;
			if(tr[st]!=tra[st])
			mark = false;
			break;
		}
		if(tr[st]<c){
			st = (st<<1)+1;
    	}else{
    		st = (st<<1);
		}
	}
	return mark;
} 

bool BuildTree(char tr[], char seq[], int len){
	int i;
	bool mark = true;
	for (i=0; i < len; i++){
		mark = Insert(tr, seq[i]);
		if(!mark) break;
	}
	return mark;
}

int main(){
	int n, len;
	bool mark;
	freopen("3791.in", "r", stdin);
	freopen("3791.out", "w", stdout);
	while(scanf("%d", &n) && n){
		memset(tra, 0, sizeof(tra));
		scanf("%s", seq);
		len = strlen(seq);
		BuildTree(tra, seq, len);
		while(n--){
			scanf("%s", seq);
			len = strlen(seq);
			mark = true;
			memset(trb, 0, sizeof(trb));
			mark = BuildTree(trb, seq, len);
			if(mark){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
