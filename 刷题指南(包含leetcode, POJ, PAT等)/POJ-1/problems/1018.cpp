#include <stdio.h>
#include <stdlib.h>
int B, P;
int D;
struct CommunicationSystem {
	int bandwidth;
	int price;
	int device;
	bool used;
}device[10000];
int bandwidthOrder[10000];
int pointer[100];
int priceCmp(const void *a, const void *b)
{
	CommunicationSystem x,y;
	x=*(CommunicationSystem *)a;
	y=*(CommunicationSystem *)b;
	if (x.price < y.price)
		return -1;
	else if (x.price > y.price)
		return 1;
	else if (x.bandwidth > y.bandwidth)
		return -1;
	else if (x.bandwidth < y.bandwidth)
		return 1;
	else return 0;
}
int bandwidthCmp(const void *a, const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (device[x].bandwidth < device[y].bandwidth)
		return -1;
	else if (device[x].bandwidth > device[y].bandwidth)
		return 1;
	else return 0;
}
int main()
{
	int testCase, t;
	int i, j;
	int m, k;
	int tempP;
	CommunicationSystem temp;
	scanf("%d",&testCase);
	for (t=0; t<testCase; t++)
	{
		B = 0;
		P = 0;
		tempP = 0;
		scanf("%d",&D);
		for (i=0, j=0; i<D; i++)
		{
			scanf("%d",&m);
			pointer[i] = j;
			
			for (k=0; k<m; k++,j++)
			{
				scanf("%d%d",&device[j].bandwidth, &device[j].price);
				device[j].device = i;
				device[j].used = false;
				bandwidthOrder[j] = j;
			}
			qsort(device+j-m, m, sizeof(device[0]), priceCmp);
			tempP += device[pointer[i]].price;
		}
		qsort(bandwidthOrder, j, sizeof(bandwidthOrder[0]), bandwidthCmp);
		for (i=0; i<=j-D; i++)
		{
			temp = device[bandwidthOrder[i]];
			
			device[bandwidthOrder[i]].used = true;
			tempP -= device[pointer[temp.device]].price;
			if (P == 0 || B * (tempP + temp.price) < temp.bandwidth * P)
			{
				P = tempP + temp.price;
				B = temp.bandwidth;
			}
			while (device[pointer[temp.device]].used == true && temp.device == device[pointer[temp.device]].device) {
				pointer[temp.device]++;
			}
			if (temp.device != device[pointer[temp.device]].device)
				break;
			tempP += device[pointer[temp.device]].price;
			
		}
		printf("%.3lf\n", (double)(1.0 * B / P));
	}
	return 0;
}

