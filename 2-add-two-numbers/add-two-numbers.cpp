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
    void insertAtTail(ListNode* &l3,int data){
        ListNode* nn=new ListNode(data);
        if(l3==NULL){
            l3=nn;
            return;
        }
        ListNode* temp=l3;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* list3 = NULL;

        int sum=0;
        int carry=0;
        while(temp1!=NULL && temp2!=NULL){
            int total=temp1->val + temp2->val + carry;
            int sum = total%10;
            insertAtTail(list3,sum);
            carry=total/10;
            temp1=temp1->next;
            temp2=temp2->next;
        }

        while(temp1!=NULL){
            int total=temp1->val + carry;
            int sum = total%10;
            insertAtTail(list3,sum);
            carry=total/10;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int total=temp2->val + carry;
            int sum = total%10;
            insertAtTail(list3,sum);
            carry=total/10;
            temp2=temp2->next;
        }
        while(carry!=0){
           int total= carry;
            int sum = total%10;
            insertAtTail(list3,sum);
            carry=total/10; 
        }
        return list3;
    }
};