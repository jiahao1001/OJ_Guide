/*
已知满二叉树的先序序列，求其后序序列
*/

void PreToPost(ElemType pre[], int l1, int h1,
            ElemType post[], int l2, int h2)
{
  int half;
  if(h1 >= l1){
    post[h2] = pre[l1];
    half = (h1 - l1) / 2;
    PreToPost(pre, l1+1, l1+half, post, l2, l2+half-1);  //转换左子树
    PreToPost(pre, l1+half+1, h1, post, l2+half, h2-1);  //转换右子树
  }
}
