/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> vals;
    int depth = 0;
    void bfs(TreeNode* root, int depth) {
        if (root == nullptr)
            return;
        if (vals.size() <= depth) {
            vals.push_back({});
        }
        vals[depth].push_back(root->val);
        bfs(root->left, depth + 1);
        bfs(root->right, depth + 1);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return vals;
        bfs(root, depth);
        return vals;
    }
};