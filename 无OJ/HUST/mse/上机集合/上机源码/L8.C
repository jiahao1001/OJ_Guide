main()
{     int a[9];   int i;
  for(i=0;i<9;i++)
    scanf("%d",&a[i]);
   sort(a,9);  printf("\n"); for(i=0;i<9;i++)    printf(" %d",a[i]);
   printf("\n");
}
sort(s,n)
int s[];
int n;
{ int i,j,t; i=0; j=n-1;
 for(;i<j;i++,j--)
      {
       if(s[i]>0)
	 { if(s[j]<0)
	    {t=s[i]; s[i]=s[j];s[j]=t;}
	     else    i--;
	     }
      else
	{
	  if(s[j]<0) j++;

	}}}