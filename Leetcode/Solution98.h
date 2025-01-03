#pragma once

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <stack>
using namespace std;
class Solution98 {
public:
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);

        for (size_t i = 0; i < vals.size() - 1; ++i) {
            if (vals[i] >= vals[i + 1]) {
                return false;
            }
        }
        return true;
    }
};