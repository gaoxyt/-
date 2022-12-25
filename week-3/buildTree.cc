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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& inorder, int i_start, int i_end, vector<int>& postorder, int p_start, int p_end) {
        if (p_start > p_end || i_start > i_end) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[p_end]);
        int left_num = 0;
        for (int i = i_start; i <= i_end; i++) {
            if (inorder[i] == postorder[p_end]) {
                left_num = i - i_start;
                break;
            }
        }
        root->left = build(inorder, i_start, i_start + left_num - 1, postorder, p_start, p_start + left_num - 1);
        root->right = build(inorder, i_start + left_num + 1, i_end, postorder, p_start + left_num, p_end - 1);
        return root;
    }
};
