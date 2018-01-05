main()
{  int i=0,j=0,k=0,m=0,t=0;
 for(m=0;m<=100;m++)
  for(t=100;t<=999;t++)
   {
    i=t/100;  j=(t-i*100)/10;  k=(t-i*100-j*10);

    if(((i==j)||(j==k)||(i==k))&&(t==m*m))

	printf(" \n%3d\n",t);
   }

}