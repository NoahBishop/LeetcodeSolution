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
class Solution700 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root) {
            while (root) {
                if (root->val == val) {
                    break;
                }
                else if (root->val > val) {
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
        }
        return root;
    }
};