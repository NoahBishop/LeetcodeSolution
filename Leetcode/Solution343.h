#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;


class Solution343 {
public:
    int integerBreak(int n) {
        // 定义dp[i]为对i分解能得到的最大值
        // 令 j 为分解的第一个数字
        // dp[i] 的转移为直接分2个 或者 对剩余继续分解
        // 因为乘法是结合率保持max会累积
        // 那么dp[i] = max(j * (i - j), j * dp[i - j]);
        // dp[2] = 1 x 1 = 1;
        int dp[59] = { 0 };
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                // 因为之前有记录，需要再比较一次
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        return dp[n];
    }
};