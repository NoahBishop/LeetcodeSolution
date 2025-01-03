#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution746 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 定义dp[i]为到达台阶i需要花费的最小花费
        // 可以从0或者1选择出发
        // dp[0] = 0; //第0级不用
        // dp[1] = 0; //第1级不用
        // 第2级开始，之后可以从下面2级别选择
        // 这级花费为从前1级出发或者前2级出发
        // dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        int dp[1001] = { 0 };

        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }

        return dp[cost.size()];
    }
};