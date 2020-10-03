/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    Node *temp=head, *current=head;
    if(head== NULL || head->next== NULL)
        return false;
    while(temp!=NULL)
    {
        current= current->next;
        temp= temp->next->next;
        if(temp==current)
            return true;
    }
    return false;
    
}
