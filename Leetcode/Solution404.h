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
class Solution404 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        sum += sumOfLeftLeaves(root->right);

        if (root->left && (root->left->left != nullptr || root->left->right != nullptr)) {
            // ������Ҷ�ӣ������ܺ�
            sum += sumOfLeftLeaves(root->left);
        }
        else if(root->left && root->left->left == nullptr && root->left->right == nullptr) {
            // ����Ҷ�ӣ���¼ֵ
            sum += root->left->val;
        }

        return sum;
    }
};