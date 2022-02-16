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
    
    int length(ListNode* head)
    {
        if(head==0)
        {
            return 0;
        }
        if(head->next==NULL)
        {
            return 1;
        }
        ListNode *temp = head;
        int c = 0;
        while(temp!=NULL)
        {
            temp = temp->next;
            c++;
        }
        return c;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
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
        int f = length(head);
        if(f < k)
        {
            return head;
        }
        while(nn!=NULL &&  i < k )
        {
            nn = nn->next;
            curr->next = prev;
            prev = curr;
            curr = nn;
            i++;
        }
        if(nn!=0)
        {
            head->next = reverseKGroup(nn , k);
        }
        return prev;
    }
};
