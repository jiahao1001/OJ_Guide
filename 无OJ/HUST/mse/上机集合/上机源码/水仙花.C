main()
{ int i=0,m=0,j=0,s=0,t=0;
for(i=1;i<=9;i++)
 for(j=0;j<=9;j++)
   for(s=0;s<=9;s++)
	{t=i*100+j*10+s;
	  if(t==(i*i*i+j*j*j+s*s*s)) printf("\n%3d",t);
	}


}