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
    int length(ListNode* head){
        ListNode* temp=head;
        int len=1;
        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int len=length(head);
        if(k>=len){
            k = k % len;
        }
        while(k){
            ListNode* temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }

            ListNode* tail=temp->next;
            temp->next=NULL;
            tail->next=head;
            head=tail;
            k--;
        }
        return head;
    }
};