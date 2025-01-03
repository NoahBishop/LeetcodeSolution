#pragma once
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int res = 0;

    int postorder(TreeNode* root) {
        if (!root) {
            return 2;
        }
        int left = postorder(root->left);
        int right = postorder(root->right);


        // 左右都是被辐射到的，当前节点返回0
        if (left == 2 && right == 2) {
            return 0;
        }

        // 左右有一个无法被辐射
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }

        // 左右有一个是摄像机，自己可以被辐射，返回辐射状态
        if (left == 1 || right == 1) {
            return 2;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        int n = postorder(root);
        if (n == 0) {
            res++;
        }
        return res;
    }
};