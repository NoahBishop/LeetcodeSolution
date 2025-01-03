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
class Solution530 {
public:
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);

        int mdis = INT32_MAX;
        for (size_t i = 0; i < vals.size() - 1; ++i) {
            int dis = vals[i + 1] - vals[i];
            if (dis < mdis) {
                mdis = dis;
            }
        }
        return mdis;
    }
};