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
class Solution112 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        stack<TreeNode*> st;
        stack<int> st_sum;
        st.push(root);
        st_sum.push(root->val);

        bool can = false;
        while (!st.empty()) {
            // 到达根节点
            if (st.top()->left == nullptr && st.top()->right == nullptr) { 
                if (st_sum.top() == targetSum) {
                    can = true;
                    break;
                }  
            }

            TreeNode* node = st.top();
            st.pop();
            int val = st_sum.top();
            st_sum.pop();

            if (node->right) {
                st.push(node->right);
                st_sum.push(val + node->right->val);
            }

            if (node->left) {
                st.push(node->left);
                st_sum.push(val + node->left->val);
            }
        }

        return can;
    }
};