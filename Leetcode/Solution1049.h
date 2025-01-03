#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution416 {
public:

	// 等价问题01背包，weight=value
	// 容量是hsum，尽可能填满，差值就是 sum - 2 * dp[hsum];
	int lastStoneWeightII(vector<int>& stones) {
		if (stones.size() == 1) {
			return stones[0];
		}

		int sum = 0;
		for (int i = 0; i < stones.size(); i++) {
			sum += stones[i];
		}
		int hsum = sum / 2;

		vector<int> dp(hsum + 1);

		for (int i = 0; i <= hsum; i++) {
			if (i >= stones[0]) {
				dp[i] = stones[0];
			}
			else {
				dp[i] = 0;
			}
		}

		for (int i = 1; i < stones.size(); i++) {
			for (int j = hsum; j >= 0; j--) {
				if (j >= stones[i]) {
					dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
				}
			}
		}

		return sum - 2 * dp[hsum];
	}
};