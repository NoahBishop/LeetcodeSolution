#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution673 {
public:
    // 定义dp[i]为以i为结束元素的序列单调长度
    // 对上一个字符，位于i - 1 位置
    // 如果nums[i] > nums[i - 1], 那么dp[i] = dp[i - 1] + 1;
    // 否则dp[i] = 1;
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(2, 1);
        dp[0] = 1;

        int maxl = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i % 2] = dp[(i - 1) % 2] + 1;
            }
            maxl = max(maxl, dp[i % 2]);
        }
        return maxl;
    }
};