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
class Solution637 {
public:
    vector<double> averageOfLevels(TreeNode* root){
        vector<double> res;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            long long sum = 0;
            int len = q.size();

            for (int i = 0; i < len; i++) {
                sum += q.front()->val;

                if (q.front()->left) {
                    q.push(q.front()->left);
                }

                if (q.front()->right) {
                    q.push(q.front()->right);
                }

                q.pop();
            }
            res.push_back(sum / double(len));
        }
        return res;
    }
};