#include<stdio.h>
int main()
{
	int i,j,k,t;
	int wk[2],wkn=0,wq[2],wqn=0,wr[2][2],wrn=0,wb[2][2],wbn=0,wn[2][2],wnn=0,wp[8][2],wpn=0;
	int bk[2],bkn=0,bq[2],bqn=0,br[2][2],brn=0,bb[2][2],bbn=0,bn[2][2],bnn=0,bp[8][2],bpn=0;
	char s[40];
	for (i=1;i<=8;i++)
	{
		gets(s);
		gets(s);
		for (j=2;j<34;j+=4)
		{
			if (s[j]==':' || s[j]=='.')
				continue;
			if (s[j]=='K')
			{
				wk[0]=(j-2)/4;
				wk[1]=9-i;
				wkn=1;
			}
			else if (s[j]=='k')
			{
				bk[0]=(j-2)/4;
				bk[1]=9-i;
				bkn=1;
			}
			else if (s[j]=='Q')
			{
				wq[0]=(j-2)/4;
				wq[1]=9-i;
				wqn=1;
			}
			else if (s[j]=='q')
			{
				bq[0]=(j-2)/4;
				bq[1]=9-i;
				bqn=1;
			}
			else if (s[j]=='R')
			{
				wr[wrn][0]=(j-2)/4;
				wr[wrn][1]=9-i;
				wrn++;
			}
			else if (s[j]=='r')
			{
				br[brn][0]=(j-2)/4;
				br[brn][1]=9-i;
				brn++;
			}
			else if (s[j]=='B')
			{
				wb[wbn][0]=(j-2)/4;
				wb[wbn][1]=9-i;
				wbn++;
			}
			else if (s[j]=='b')
			{
				bb[bbn][0]=(j-2)/4;
				bb[bbn][1]=9-i;
				bbn++;
			}
			else if (s[j]=='N')
			{
				wn[wnn][0]=(j-2)/4;
				wn[wnn][1]=9-i;
				wnn++;
			}
			else if (s[j]=='n')
			{
				bn[bnn][0]=(j-2)/4;
				bn[bnn][1]=9-i;
				bnn++;
			}
			else if (s[j]=='P')
			{
				wp[wpn][0]=(j-2)/4;
				wp[wpn][1]=9-i;
				wpn++;
			}
			else if (s[j]=='p')
			{
				bp[bpn][0]=(j-2)/4;
				bp[bpn][1]=9-i;
				bpn++;
			}
		}
	}
	if (wrn>1)
	{
		if (wr[0][1]>wr[1][1])
		{
			t=wr[0][1];
			wr[0][1]=wr[1][1];
			wr[1][1]=t;
			t=wr[0][0];
			wr[0][0]=wr[1][0];
			wr[1][0]=t;
		}
		else if (wr[0][1]==wr[1][1])
		{
			if (wr[0][0]>wr[1][0])
			{
				t=wr[0][1];
				wr[0][1]=wr[1][1];
				wr[1][1]=t;
				t=wr[0][0];
				wr[0][0]=wr[1][0];
				wr[1][0]=t;
			}
		}
	}
	if (wbn>1)
	{
		if (wb[0][1]>wb[1][1])
		{
			t=wb[0][1];
			wb[0][1]=wb[1][1];
			wb[1][1]=t;
			t=wb[0][0];
			wb[0][0]=wb[1][0];
			wb[1][0]=t;
		}
		else if (wb[0][1]==wb[1][1])
		{
			if (wb[0][0]>wb[1][0])
			{
				t=wb[0][1];
				wb[0][1]=wb[1][1];
				wb[1][1]=t;
				t=wb[0][0];
				wb[0][0]=wb[1][0];
				wb[1][0]=t;
			}
		}
	}
	if (wnn>1)
	{
		if (wn[0][1]>wn[1][1])
		{
			t=wn[0][1];
			wn[0][1]=wn[1][1];
			wn[1][1]=t;
			t=wn[0][0];
			wn[0][0]=wn[1][0];
			wn[1][0]=t;
		}
		else if (wn[0][1]==wn[1][1])
		{
			if (wn[0][0]>wn[1][0])
			{
				t=wn[0][1];
				wn[0][1]=wn[1][1];
				wn[1][1]=t;
				t=wn[0][0];
				wn[0][0]=wn[1][0];
				wn[1][0]=t;
			}
		}
	}
	if (brn>1)
	{
		if (br[0][1]<br[1][1])
		{
			t=br[0][1];
			br[0][1]=br[1][1];
			br[1][1]=t;
			t=br[0][0];
			br[0][0]=br[1][0];
			br[1][0]=t;
		}
		else if (br[0][1]==br[1][1])
		{
			if (br[0][0]>br[1][0])
			{
				t=br[0][1];
				br[0][1]=br[1][1];
				br[1][1]=t;
				t=br[0][0];
				br[0][0]=br[1][0];
				br[1][0]=t;
			}
		}
	}
	if (bbn>1)
	{
		if (bb[0][1]<bb[1][1])
		{
			t=bb[0][1];
			bb[0][1]=bb[1][1];
			bb[1][1]=t;
			t=bb[0][0];
			bb[0][0]=bb[1][0];
			bb[1][0]=t;
		}
		else if (bb[0][1]==bb[1][1])
		{
			if (bb[0][0]>bb[1][0])
			{
				t=bb[0][1];
				bb[0][1]=bb[1][1];
				bb[1][1]=t;
				t=bb[0][0];
				bb[0][0]=bb[1][0];
				bb[1][0]=t;
			}
		}
	}
	if (bnn>1)
	{
		if (bn[0][1]<bn[1][1])
		{
			t=bn[0][1];
			bn[0][1]=bn[1][1];
			bn[1][1]=t;
			t=bn[0][0];
			bn[0][0]=bn[1][0];
			bn[1][0]=t;
		}
		else if (bn[0][1]==bn[1][1])
		{
			if (bn[0][0]>bn[1][0])
			{
				t=bn[0][1];
				bn[0][1]=bn[1][1];
				bn[1][1]=t;
				t=bn[0][0];
				bn[0][0]=bn[1][0];
				bn[1][0]=t;
			}
		}
	}
	for (j=0;j<wpn;j++)
	{
		for (k=j+1;k<wpn;k++)
		{
			if (wp[j][1]>wp[k][1])
			{
				t=wp[j][1];
				wp[j][1]=wp[k][1];
				wp[k][1]=t;
				t=wp[j][0];
				wp[j][0]=wp[k][0];
				wp[k][0]=t;
			}
			else if (wp[j][1]==wp[k][1])
			{
				if (wp[j][0]>wp[k][0])
				{
					t=wp[j][1];
					wp[j][1]=wp[k][1];
					wp[k][1]=t;
					t=wp[j][0];
					wp[j][0]=wp[k][0];
					wp[k][0]=t;
				}
			}
		}
	}
	for (j=0;j<bpn;j++)
	{
		for (k=j+1;k<bpn;k++)
		{
			if (bp[j][1]<bp[k][1])
			{
				t=bp[j][1];
				bp[j][1]=bp[k][1];
				bp[k][1]=t;
				t=bp[j][0];
				bp[j][0]=bp[k][0];
				bp[k][0]=t;
			}
			else if (bp[j][1]==bp[k][1])
			{
				if (bp[j][0]>bp[k][0])
				{
					t=bp[j][1];
					bp[j][1]=bp[k][1];
					bp[k][1]=t;
					t=bp[j][0];
					bp[j][0]=bp[k][0];
					bp[k][0]=t;
				}
			}
		}
	}
	gets(s);
	printf("White: ");
	for (j=0;j<wkn;j++)
		printf("K%c%d",wk[0]+'a',wk[1]);
	for (j=0;j<wqn;j++)
		printf(",Q%c%d",wq[0]+'a',wq[1]);
	for (j=0;j<wrn;j++)
		printf(",R%c%d",wr[j][0]+'a',wr[j][1]);
	for (j=0;j<wbn;j++)
		printf(",B%c%d",wb[j][0]+'a',wb[j][1]);
	for (j=0;j<wnn;j++)
		printf(",N%c%d",wn[j][0]+'a',wn[j][1]);
	for (j=0;j<wpn;j++)
		printf(",%c%d",wp[j][0]+'a',wp[j][1]);
	printf("\nBlack: ");
	for (j=0;j<bkn;j++)
		printf("K%c%d",bk[0]+'a',bk[1]);
	for (j=0;j<bqn;j++)
		printf(",Q%c%d",bq[0]+'a',bq[1]);
	for (j=0;j<brn;j++)
		printf(",R%c%d",br[j][0]+'a',br[j][1]);
	for (j=0;j<bbn;j++)
		printf(",B%c%d",bb[j][0]+'a',bb[j][1]);
	for (j=0;j<bnn;j++)
		printf(",N%c%d",bn[j][0]+'a',bn[j][1]);
	for (j=0;j<bpn;j++)
		printf(",%c%d",bp[j][0]+'a',bp[j][1]);
	printf("\n");
	return 0;
}
