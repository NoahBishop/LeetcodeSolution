#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution139 {
public:

	// �ȼ�����ȫ����,��¼�ǳ���(����)Ϊj��ʱ��ɲ����Ա���ϳ���
	// ������j,��¼dp[i][j]Ϊѡȡ����0-iԪ��,����Ϊj�ܷ����
	// ת�ƹ�ʽ��dp[j] = dp[j] || dp[j - str[i].size()] && cmp(str[i], s(j - str[i].size(), j));
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