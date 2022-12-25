/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        std::vector<int> vec;
        TraverseTree(root, vec);
        int len = vec.size();
        std::map<int, int> mp;
        mp[vec[len-1]] = 0;
        for (int i = len - 2; i >= 0; i--) {
            mp[vec[i]] += mp[vec[i+1]] + vec[i+1];
        }
        return convert(root, mp);
    }

    void TraverseTree(TreeNode* root, std::vector<int> &vec) {
        if (!root) return;
        TraverseTree(root->left, vec);
        vec.push_back(root->val);
        TraverseTree(root->right, vec);
    }    

    TreeNode* convert(TreeNode* root, std::map<int, int>& mp) {
        if(!root) return nullptr;
        TreeNode* new_root = new TreeNode(root->val + mp[root->val]);
        new_root->left = convert(root->left, mp);
        new_root->right = convert(root->right, mp);
        return new_root;
    }
};
