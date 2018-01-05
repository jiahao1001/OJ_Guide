#include<stdio.h>

const int maxstep=9;
int target_x;
int target_y;

int num;
int path[9][2];
int dx[5]={0,1,2,2,1};
int dy[5]={0,2,1,-1,-2};
int mk9];

void jump(int x,int y,int step)
{
	int k,i,j;
	int t1,t2,t3,t4;
	int x1,y1;
	 
	for(k=1;k<=4;k++)
	{
		x1=x+dx[k];
		y1=y+dy[k];    

		t1=(x1>0)&&(x1<=target_x);
		t2=(y1>0)&&(y1<=target_y);          
		t3=(x1==target_x)&&(y1!=target_y);  
		t4=(x1==target_x)&&(y1==target_y);    

		if((t1)&&(t2)&&(!t3))
		{
			path[step][0]=x1;
			path[step][1]=y1;
			mk[step]=k;            
			if(t4)                 
			{
				num++;                 
				
				printf("num:%-2d",num);
				printf(" road:");
				for(i=0;i<=step;i++)
				{
				printf("%3d,%d",path[i][0],path[i][1]);	
				}
				printf("\n");
                
				printf("     mothed:");
				for(i=1;i<=step;i++)
                {
                 j=mk[i];
				 printf("%3d,%d",dx[j],dy[j]);	
				}
                printf("\n\n");         
			}

			else
			{
				jump(x1,y1,step+1);     
			}
		}
	}
}

void main()
{
loopx:printf("please input target_x(1-9):");   
      scanf("%d",&target_x);
	  if(!(target_x<=9&&target_x>=9)) 
	  {
      printf("warning:the target_x is must between 1 and 9\n");
	  goto loopx;
	  }
    
	  else
loopy:printf("please input target_y(1-5):");
      scanf("%d",&target_y);
 	  if(!(target_y<=5&&target_y>=1)) 
	  {
	  printf("warning:the target_y is must between 1 and 5\n");
	  goto loopy;
	  }
      else  
	  printf("\n");
	  mk[0]=0;
	  num=0;
	  path[0][0]=1;
      path[0][1]=1;
      jump(1,1,1);
      printf("\n");
      printf("总方案数：%d\n",num);
}
