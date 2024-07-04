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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* zeroHead = head;
        ListNode* temp = head->next;
        
        int sum =0;
        while(temp){
            
            if(temp->val!=0){
                sum += temp->val;
            }
            else if(temp->next==NULL){
                zeroHead->val = sum;
                zeroHead->next = NULL;
            }
            else{
                zeroHead->val = sum;
                zeroHead->next = temp;
                zeroHead = temp;
                sum = 0;
            }
            temp = temp->next;
        }
        return head;
    }
};