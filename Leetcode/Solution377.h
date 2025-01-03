#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution377 {
public:

	// 等价问题全背包,但是记录不是装多少,记录的是装满有多少排列方式
	// 容量是j,记录dp[i][j]为选取任意0-i元素,容量为j是填充满的有多少排列方式
	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned long long> dp(target + 1, 0);
		dp[0] = 1;

		for (int j = 0; j <= target; j++) {
			for (int i = 0; i < nums.size(); i++) {
				if (j - nums[i] >= 0) {
					dp[j] += dp[j - nums[i]];
				}
			}
		}

		return dp[target];
	}
};