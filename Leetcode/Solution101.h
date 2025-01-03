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
#include <queue>
using namespace std;
class Solution101 {
public:
    bool cmpMirror(TreeNode* left, TreeNode* right) {
        if ((left == nullptr && right != nullptr) || (right == nullptr && left != nullptr)) {
            return false;
        }
        else if (left == nullptr && right == nullptr) {
            return true;
        }
        else {
            return (cmpMirror(left->left, right->right) && cmpMirror(left->right, right->left) && left->val == right->val);
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return cmpMirror(root->left, root->right);
    }
};