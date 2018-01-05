#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

double add(double);
int main(){
	freopen("2011.in", "r", stdin);
	freopen("2011.out", "w", stdout);
	int x;
	scanf("%d", &x);
	int i = 0;
	double ans[x];
	while(i < x){
		scanf("%lf", &ans[i]);
		printf("%.2f\n", add(ans[i]));
		i++;
	}
}
double add(double n){
	double y(0), i, t, g(1);
	for(i = 1; i <= n; i++){
		t = 1 / i;
		y += (g * t);
		g = (-g);
	}
	return y;
} 
	 
	
