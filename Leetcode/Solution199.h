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
class Solution199 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            int len = q.size();

            for (int i = 0; i < len; i++) {
                if (i == len - 1) {
                    res.push_back(q.front()->val);
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
        return res;
    }
};