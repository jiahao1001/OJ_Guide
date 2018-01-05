/*
求先序遍历序列中第k个结点的值
*/

int i=1;
ElemType PreNode(BiTree b, int k)
{
  ElemType ch;
  if(b==NULL)
      return '#';
  if(i==k)
      return b->data;
  i++;
  ch=PreNode(b->lchild, k);
  if(ch!='#')
      return ch;
  ch = PreNode(b->rchild, k);
      return ch;
}
