/****************************************************
* problem id : 206
* problem title : Reverse Linked List
* problem link : https://leetcode.com/problems/reverse-linked-list/description/
*****************************************************/

ListNode* reverseList(ListNode* head) {
    if(NULL==head) return head;

  ListNode *p=head;
  p=head->next;
  head->next=NULL;
  while(NULL!=p){
    ListNode *ptmp=p->next;
    p->next=head;
    head=p;
    p=ptmp;
  }
  return head;
}
