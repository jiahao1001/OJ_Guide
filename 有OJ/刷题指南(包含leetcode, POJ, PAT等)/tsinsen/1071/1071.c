#include <stdio.h>
#include <stdlib.h>


struct p
{
    int num;
    int grade;
};

int cmp ( const void *a , const void *b ){
  struct p *ap=(struct p *)a;
  struct p *bp=(struct p *)b;
  if(ap->grade!=bp->grade)return bp->grade-ap->grade;
  return ap->num-bp->num;
}

struct p a[5000];

int main()
{
    int n,m,g,i;
    scanf("%d%d",&n,&m);
    m=m*1.5;

    for(i=0;i<n;i++)
        scanf("%d%d",&a[i].num,&a[i].grade);


    qsort(a,n,sizeof(struct p),cmp);

    i=a[m-1].grade;
    while(a[m].grade==i)m++;

    printf("%d %d\n",a[m-1].grade,m);
    for(i=0;i<m;i++)
        printf("%d %d\n",a[i].num,a[i].grade);

    return 0;
}