/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL){
            return NULL;
        }
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevOfSlow = NULL;
        while(fast->next!=NULL){
            prevOfSlow = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast->next!=NULL){
                fast = fast->next;
            }
        }
        prevOfSlow->next = slow->next;
        delete(slow);
        return head;
    }
};