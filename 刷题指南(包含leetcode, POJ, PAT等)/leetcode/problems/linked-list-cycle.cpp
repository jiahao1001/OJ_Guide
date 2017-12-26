/**************************************************************
* problem id : 141
* problem title : Linked List Cycle
* problem link : https://leetcode.com/problems/linked-list-cycle/description/
**************************************************************/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slower=head, *faster=head;

        if(head==nullptr)
            return false;
        while(faster->next!=nullptr && faster->next->next!=nullptr) {
            slower = slower->next;
            faster = faster->next->next;
            if(slower==faster)
                return true;
        }
        return false;
    }
};
