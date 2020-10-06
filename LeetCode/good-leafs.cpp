/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt=0;
    vector<int> dfs(TreeNode* root, int distance){
        vector<int> p;
        if(root==NULL){
            return p;
        }
        auto left=dfs(root->left,distance);
        auto right=dfs(root->right,distance);
        
        if(root->left == NULL && root->right ==NULL){
            p.push_back(1);
            return p;
        }
        for(int i=0; i<left.size(); i++){
            for(int j=0; j<right.size(); j++){
                if(left[i]+right[j]<=distance){
                    cnt++;      
                }
            }
        }
        for(int i=0;i<left.size(); i++){
            p.push_back(++left[i]);
        }
        for(int i=0;i<right.size(); i++){
            p.push_back(++right[i]);
        }
        return p;
    }
    int countPairs(TreeNode* root, int distance) {
        auto ans=dfs(root,distance);
        return cnt;
    }
}
