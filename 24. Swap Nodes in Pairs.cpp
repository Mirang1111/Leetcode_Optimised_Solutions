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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==0)
        {
            return head;
        }
        if(head->next==0)
        {
            return head;
        }
        
        ListNode *nn = head;
        ListNode *curr = head;
        ListNode *prev = 0;
        int i = 0;
        int k = 2;
        while(nn!=NULL && i < k)
        {
            nn = nn->next;
            curr->next = prev;
            prev = curr;
            curr = nn;
            i++;
        }
        if(nn!=0)
        {
            head->next = swapPairs(nn);
        }
        return prev;
    }
};
