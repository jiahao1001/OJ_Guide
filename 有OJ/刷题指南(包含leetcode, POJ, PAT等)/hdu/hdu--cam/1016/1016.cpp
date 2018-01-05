#include<cstdio>
#include<cstring>

int prime[40] = {0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0},n;
int visited[21],a[21];
void DFS(int num){
	int i;
	if(num==n&&prime[a[num-1]+a[0]]){
		for(i=0; i<num-1;i++)
			printf("%d ", a[i]);
		printf("%d\n", a[num-1]);
	}
	else{
		for(i=2; i<=n; i++){
			if(visited[i] == 0){
				if(prime[i+a[num-1]]){
					visited[i]= -1; 
					a[num++] = i;
					DFS(num);
					visited[i]=0;
					num--;
				}
			}
		}
	}
}
int main(){
	freopen("1016.in", "r", stdin);
	freopen("1016.out", "w", stdout);	
	int num=0;
	while(~scanf("%d", &n)){
		num++;
		printf("Case %d:\n", num);
		memset(visited, 0, sizeof(visited));
		a[0] = 1;
		DFS(1);
		printf("\n");
	}
	return 0;
}
