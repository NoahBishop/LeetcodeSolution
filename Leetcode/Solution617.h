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
class Solution617 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(0);
        if (root1 && !root2) {
            node->val = root1->val;
            node->right = mergeTrees(root1->right, nullptr);
            node->left = mergeTrees(root1->left, nullptr);
        }
        else if (!root1 && root2) {
            node->val = root2->val;
            node->right = mergeTrees(nullptr, root2->right);
            node->left = mergeTrees(nullptr, root2->left);
        }
        else if (root1 && root2) {
            node->val = (root1->val + root2->val);
            node->right = mergeTrees(root1->right, root2->right);
            node->left = mergeTrees(root1->left, root2->left);
        }

        return node;
    }
};