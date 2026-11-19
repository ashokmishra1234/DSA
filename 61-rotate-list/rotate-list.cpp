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
   
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int cntNodes=0;
        ListNode* temp=head;
        while(temp){
            cntNodes+=1;
            temp=temp->next;
        }
        k=k%cntNodes;
        if(k==0) return head;
        int target=cntNodes-k-1;
        temp=head;
        while(target && temp){
            temp=temp->next;
            target-=1;
        }
        ListNode* nextHead=temp->next;
        temp->next=nullptr;
        ListNode *dummy=nextHead;
        while(dummy && dummy->next){
            dummy=dummy->next;
        }
        dummy->next=head;
        return nextHead;
    }
};