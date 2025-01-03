#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution416 {
public:

	// 等价问题01背包，weight=value
	// 容量是sum，且需要填满
    bool canPartition(vector<int>& nums) {
		if (nums.size() == 1) {
			return false;
		}

		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}

		if (sum % 2 != 0) return false;

		sum /= 2;
		vector<int> dp(sum + 1);

		for (int i = 0; i <= sum; i++) {
			if (i >= nums[0]) {
				dp[i] = nums[0];
			}
			else {
				dp[i] = 0;
			}
		}

		for (int i = 1; i < nums.size(); i++) {
			for (int j = sum; j >= 0; j--) {
				if (j >= nums[i]) {
					dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
				}
			}
		}

		return dp[sum] == sum;
    }
};