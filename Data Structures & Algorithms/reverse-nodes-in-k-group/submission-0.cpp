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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp1=head;
        ListNode* prevTail=NULL;
        ListNode* newHead=NULL;
        while(temp1!=NULL){
            ListNode* temp2=temp1;
            int count=1;
            while(temp2!=NULL && count<k){
                temp2=temp2->next;
                count++;
            }
            if(temp2==NULL){
                break;
            }
            ListNode* nextgroup=temp2->next;
            ListNode* groupTail=temp1;
            temp2->next=NULL;
            ListNode* grouphead=reverse(temp1);
            if (newHead==NULL) {
                newHead=grouphead;
            }
            if (prevTail!=NULL) {
                prevTail->next=grouphead;
            }
            groupTail->next=nextgroup;
            prevTail=groupTail;
            temp1=nextgroup;
        }
        if (newHead==NULL)
            return head;

        return newHead;

    }
};
