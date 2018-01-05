main()
{    long s[30],i,j;  s[1]=1,s[2]=1;

    for(i=3;i<30;i++)
	s[i]=s[i-1]+s[i-2] ;
   for(j=0;j<30;j++)
 printf("%ld  ",s[j]);
}
