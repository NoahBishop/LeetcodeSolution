#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution198 {
public:
    // 只能考虑相隔偷窃
    // dp[i] 为考虑偷窃前i家得到的最大金额
    // 偷或者不偷从之前的状态转移来
    // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int dp_0 = nums[0], dp_1 = max(nums[0], nums[1]), dp_2;

        for (int i = 2; i < nums.size(); i++) {
            dp_2 = max(dp_0 + nums[i], dp_1);
            dp_0 = dp_1;
            dp_1 = dp_2;
        }

        return dp_1;
    }
};