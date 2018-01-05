main()
{  char str[30];    int i;
   gets(str);
   for(i=0;str[i]!='\0';i++)
      if(i%2&&(str[i]<'z'&&str[i]>'a')) str[i]=str[i]-'a'+'A';

 printf("\n%s\n",str);

}