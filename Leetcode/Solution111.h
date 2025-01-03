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
#include <queue>
using namespace std;
class Solution111 {
public:
    int minDepth(TreeNode* root) {
        int deep = 0;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            int len = q.size();
            deep++;
            for (int i = 0; i < len; i++) {
                if (q.front()->right == nullptr && q.front()->left == nullptr) {
                    return deep;
                }

                if (q.front()->left) {
                    q.push(q.front()->left);
                }

                if (q.front()->right) {
                    q.push(q.front()->right);
                }

                q.pop();
            }
        }
        return deep;
    }
};