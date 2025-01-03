#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution337 {
public:
    map<TreeNode*, int> dp;

    // 只能考虑相隔偷窃
    // dp[i] 为考虑偷窃节点i为根的子数得到的最大金额
    // 偷或者不偷从之前的状态转移来
    // dp[i] = max(dp[i->left->left] + dp[i->left->right] + dp[i->right->left] + dp[i->right->left] + nums[i],
    // dp[i->left] + dp[i->right]);
    int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }

        int left = rob(root->left);
        int right = rob(root->right);

        int not_choose_root = left + right;

        int choose_root = root->val;
        if (root->left) {
            choose_root += rob(root->left->left);
            choose_root += rob(root->left->right);
        }
        if (root->right) {
            choose_root += rob(root->right->left);
            choose_root += rob(root->right->right);
        }

        dp[root] = max(not_choose_root, choose_root);

        return dp[root];
    }
};