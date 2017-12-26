/**************************************************************
* problem id : 21
* problem title : Merge Two Sorted Lists
* problem link : https://leetcode.com/problems/merge-two-sorted-lists/description/
***************************************************************/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *cur=new ListNode(0), *cur1=l1, *cur2=l2;

        while(cur1!=nullptr && cur2!=nullptr) {
            if(cur1->val<cur2->val) {
                cur->next = cur1;
                cur = cur1;
                cur1 = cur1->next;
            }
            else {
                cur->next = cur2;
                cur = cur2;
                cur2 = cur2->next;
            }
        }
        if(cur1!=nullptr)
            cur->next = cur1;
        if(cur2!=nullptr)
            cur->next = cur2;

        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        return (l1->val<l2->val)?l1:l2;
    }
};
