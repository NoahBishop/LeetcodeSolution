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


        // ���Ҷ��Ǳ����䵽�ģ���ǰ�ڵ㷵��0
        if (left == 2 && right == 2) {
            return 0;
        }

        // ������һ���޷�������
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }

        // ������һ������������Լ����Ա����䣬���ط���״̬
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