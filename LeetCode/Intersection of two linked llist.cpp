/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp,*tempA,*tempB;
        tempA=headA;
        tempB=headB;
        temp=NULL;
        int flag=0;
        while(headA!=NULL)
        {
            while(headB!=NULL)
            {
                if(headA==headB)
                {
                    flag=1;
                    temp=headA;
                    break;
                }
                headB=headB->next;
            }
            if(flag==1)
                break;
            headB=tempB;
            headA=headA->next;
        }
    return temp;
    }
    
};