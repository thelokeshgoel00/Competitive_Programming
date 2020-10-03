
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        int h1=0,h2 =0;
        if(root->left!=NULL)
            h1= 1+ height(root->left);
        if(root->right!=NULL)
            h2= 1+ height(root->right);
        return (h1>h2)?h1:h2;
        // Write your code here.
    }
  