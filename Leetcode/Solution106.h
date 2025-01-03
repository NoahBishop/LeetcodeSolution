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
class Solution106 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return nullptr;
        }

        int mid = *(postorder.end() - 1);
        int left = 0;
        auto k = find(inorder.begin(), inorder.end(), mid);
        vector<int> left_inorder(inorder.begin(), k);
        vector<int> right_inorder(k + 1, inorder.end());

        vector<int> left_postorder(postorder.begin() , postorder.begin() + left_inorder.size());
        vector<int> right_postorder(postorder.begin() + left_inorder.size() + 1, postorder.end() - 1);

        /*for (left = 0; left < inorder.size(); left++) {
            if (inorder[left] == mid) {
                break;
            }
            else {
                left_inorder.push_back(inorder[left]);
            }
        }

        for (int i = left + 1; i < inorder.size(); i++) {
            right_inorder.push_back(inorder[i]);
        }

        for (int i = 0; i < left; i++) {
            left_postorder.push_back(postorder[i]);
        }

        for (int i = left; i < postorder.size() - 1; i++) {
            right_postorder.push_back(postorder[i]);
        }*/

        TreeNode* left_tree = buildTree(left_inorder, left_postorder);
        TreeNode* right_tree = buildTree(right_inorder, right_postorder);

        TreeNode* node = new TreeNode(mid);
        node->left = left_tree;
        node->right = right_tree;

        return node;
    }
};