#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution300 {
public:
    // 定义dp[i]为以i为结束元素的组合单调长度
    // 对过去出现的所有字符，位于j位置(0 <= j < i)
    // 如果nums[i] > nums[j], 那么dp[i] = max(dp[i], dp[j] + 1);
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;

        int maxl = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxl = max(maxl, dp[i]);
        }
        return maxl;
    }
};