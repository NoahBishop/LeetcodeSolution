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
class Solution105 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }

        int mid = *(preorder.begin());
        int left = 0;
        auto k = find(inorder.begin(), inorder.end(), mid);
        vector<int> left_inorder(inorder.begin(), k);
        vector<int> right_inorder(k + 1, inorder.end());

        vector<int> left_pretorder(preorder.begin() + 1, preorder.begin() + 1 + left_inorder.size());
        vector<int> right_pretorder(preorder.begin() + 1 + left_inorder.size(), preorder.end());

        TreeNode* left_tree = buildTree(left_pretorder, left_inorder);
        TreeNode* right_tree = buildTree(right_pretorder, right_inorder);

        TreeNode* node = new TreeNode(mid);
        node->left = left_tree;
        node->right = right_tree;

        return node;
    }
};