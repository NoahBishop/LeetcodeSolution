#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution139 {
public:

	// 等价问题全背包,记录是长度(容量)为j的时候可不可以被组合出来
	// 容量是j,记录dp[i][j]为选取任意0-i元素,容量为j能否被组合
	// 转移公式是dp[j] = dp[j] || dp[j - str[i].size()] && cmp(str[i], s(j - str[i].size(), j));
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size() + 1, 0);
		dp[0] = 1;

		for (int j = 0; j <= s.size(); j++) {
			for (int i = 0; i < wordDict.size(); i++) {
				int dis = j - wordDict[i].length();
				if (dis >= 0) {
					string cpstr(s.begin() + j - wordDict[i].size(), s.begin() + j);
					dp[j] = dp[j] || (dp[j - wordDict[i].size()] && (wordDict[i] == cpstr));
				}
			}
		}

		return dp[s.size()];
	}
};