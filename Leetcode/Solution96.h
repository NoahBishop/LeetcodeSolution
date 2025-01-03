#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;


class Solution96 {
public:
    int numTrees(int n) {
        // 定义dp[i]为对长度为i的连续序列，能构建的2叉树排列方式
        // dp[0] = 1; // 0 就是空节点一种
        // dp[1] = 1; // 1 就是 1种
        // 从i=2开始， 估计从中选每个节点作为根节点
        // 令节点左侧数量是j, 右边是i - 1 - j, 循环0 <= j <= i - 1;
        // dp[i] += dp[j] * dp[i - 1 - j];
        int dp[20] = { 0 };
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[n];
    }
};