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
    TreeNode* solve(const vector<int>& preorder, int& preIdx, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = inMap[rootVal];

        root->left = solve(preorder, preIdx, inStart, inRoot - 1, inMap);
        root->right = solve(preorder, preIdx, inRoot + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        int preIdx = 0;
        return solve(preorder, preIdx, 0, inorder.size() - 1, inMap);
    }
};