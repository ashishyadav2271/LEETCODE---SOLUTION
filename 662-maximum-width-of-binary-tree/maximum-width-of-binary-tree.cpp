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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unsigned long long maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        while (!q.empty()) {
            int n = q.size();
            unsigned long long leftMostInd = q.front().second;
            unsigned long long rightMostInd = q.back().second;        
            maxWidth = max(maxWidth, rightMostInd - leftMostInd + 1);
            for (int i = 0; i<n; i++) {
                auto front = q.front();
                q.pop();
                auto node = front.first;
                auto ind = front.second;
                if (node->left) {
                    q.push({node->left, ind*2});
                }
                if (node->right) {
                    q.push({node->right, ind*2+1});
                }
            }
        }
        return maxWidth;
    }
};