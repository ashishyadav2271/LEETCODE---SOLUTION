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
int ans=0;
int solve(TreeNode*root){
    if(!root)return 1;
    int left=solve(root->left);
    int right=solve(root->right);
    if(left==0 || right==0){
        ans++;
        return 2;
    }
    if(right==2 || left==2){
        return 1;
    }
    return 0;
}
    int minCameraCover(TreeNode* root) {
         if(solve(root)==0)ans++;
        return ans;
    }
};