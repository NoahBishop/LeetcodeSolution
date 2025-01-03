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
class Solution110 {
public:
    int getDeep(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = getDeep(root->left);
        int right = getDeep(root->right);
        
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (getDeep(root) == -1) {
            return false;
        }

        return true;
    }
};