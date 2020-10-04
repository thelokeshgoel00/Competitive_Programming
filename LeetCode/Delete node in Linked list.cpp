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
    void deleteNode(ListNode* node) {
        ListNode* temp;
        while(node->next!=NULL)
        {
            temp=node->next;
            node->val=temp->val;
            if(temp->next==NULL)    //if temp is last node
                node->next=NULL;
            else
                node=node->next;
        }
    }
};