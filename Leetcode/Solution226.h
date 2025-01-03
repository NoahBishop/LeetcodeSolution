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
class Solution226 {
public:
    void swapTree(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }

        if (root->left) {
            swapTree(root->left);
        }

        if (root->right) {
            swapTree(root->right);
        }

        swap(root->left, root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        swapTree(root);
        return root;
    }
};