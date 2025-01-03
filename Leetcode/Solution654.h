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
class Solution654 {
public:
    TreeNode* constructMaximumBinaryTreeImp(vector<int>& nums, int left, int right) {
        if (right <= left) {
            return nullptr;
        }

        int max_pos = left;
        int maxval = INT32_MIN;

        for (int i = left; i < right; i++) {
            if (maxval < nums[i]) {
                maxval = nums[i];
                max_pos = i;
            }
        }

        TreeNode* left_tree = constructMaximumBinaryTreeImp(nums, left, max_pos);
        TreeNode* right_tree = constructMaximumBinaryTreeImp(nums, max_pos + 1, right);

        TreeNode* node = new TreeNode(maxval);
        node->left = left_tree;
        node->right = right_tree;

        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTreeImp(nums, 0, nums.size());
    }
};