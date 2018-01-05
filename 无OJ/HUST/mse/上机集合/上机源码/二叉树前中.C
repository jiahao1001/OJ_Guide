 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8
typedef struct node *link;
struct node{
 int item;
  link l,r;
};
link NODE(int item)
{
 link t=malloc(sizeof *t);
t->item=item;
t->l=NULL;
t->r=NULL;
return t;
}


void pre_ord(link t)
{
  if(t==NULL) return;
 printf("%3c",t->item);
 pre_ord(t->l);
 pre_ord(t->r);
}
void in_ord(link t)
{
  if(t==NULL) return;
 in_ord(t->l);
 printf("%3c",t->item);
 in_ord(t->r);
}
void post_ord(link t)
{
  if(t==NULL) return;
 post_ord(t->l);
 post_ord(t->r);
 printf("%3c",t->item);
}

link create_tree(char *P,char *I,int n)
{  int k; link t=NULL;
if(n<=0)  return NULL;
    t=NODE(P[0]);
  for(k=0;I[k]!=P[0];k++) { ; }
  t->l=create_tree(P+1,I,k);
  t->r=create_tree(P+1+k,I+1+k,n-k-1);
  return t;
}
int main()
{
  int i;link root=NULL;

 root=create_tree("ABDECFG","DBEACGF",7);

pre_ord(root);   printf("\n");
in_ord(root);    printf("\n");
post_ord(root);  printf("\n");

return 0;
} 
 
