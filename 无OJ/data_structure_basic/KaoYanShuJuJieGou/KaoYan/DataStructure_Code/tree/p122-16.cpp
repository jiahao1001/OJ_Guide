/*
设计算法将二叉树的叶结点按从左到右的顺序连成一个单链表。
链接时用叶结点的右指针域来存放单链表指针
-----------------------
先序中序后序对于叶结点的访问都是从左到右
*/

LinkedList head, pre=NULL;

LinkedList InOrder(BiTree bt)
{
  if(bt){
    InOrder(bt->lchild);    //中序遍历左子树
    if(bt->lchild==NULL && bt->rchild==NULL)  //叶结点
        if(pre==NULL){
          head = bt;
          pre = bt;
        }
        else{
          pre->rchild = bt;
          pre = bt;
        }
        InOrder(bt->rchild);  //中序遍历右子树
        pre->rchild = NULL;
  }
  return head;
}
