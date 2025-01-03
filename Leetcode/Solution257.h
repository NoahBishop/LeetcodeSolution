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
#include <string>
#include <stack>
using namespace std;
class Solution257 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> st;
        stack<string> paths;
        vector<string> res;
        st.push(root);
        paths.push(to_string(root->val));

        while (st.empty()) {
            TreeNode* node = st.top(); st.pop();
            string path = paths.top(); paths.pop();
            if (node->left == nullptr && node->right == nullptr) {
                res.push_back(path);
            }

            if (node->left) {
                st.push(node->left);
                paths.push(path + "->" + to_string(node->left->val));
            }
            if (node->right) {
                st.push(node->right);
                paths.push(path + "->" + to_string(node->right->val));

            } 
        }
    }
};