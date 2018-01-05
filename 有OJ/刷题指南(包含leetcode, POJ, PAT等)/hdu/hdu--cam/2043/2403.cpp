#include <cstdio>
#include <cstring>

int main(){
	freopen("2043.in", "r", stdin);
	freopen("2043.out", "w", stdout);
	int n, len;
	char str[51];
	scanf("%d", &n);
	getchar();
	while (n--) {
		int sum, a(0), b(0), c(0), d(0); 
		gets(str);
		len = strlen(str); 
		for(int i = 0; i < len; i++) {
			if(str[i] >= 'A' && str[i] <= 'Z')
			a = 1;
			if(str[i] >= 'a' && str[i] <= 'z')
			b = 1;
			if(str[i] >= '0' && str[i] <= '9')
			c = 1;			
			if(str[i]=='~'||str[i]=='!'
			||str[i]=='@'||str[i]=='#'||str[i]=='$'||str[i]=='%'||str[i]=='^')
			d = 1;
		}
		sum = a+ b+ c + d;
		if(sum>2&&len >7&& len < 17) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
			
