#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution392 {
public:
    // ����dp[i][j]ΪA��iΪ����Ԫ�ص��������к�B��jΪ����Ԫ�ص����еĹ�������
    // ���s[i] == t[j], ��ôdp[i][j] = dp[i - 1][j - 1] + 1;
    // ����dp[i][j] = dp[i][j - 1];
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), 0));

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                if (s[i] == t[j]) {
                    if (i != 0 && j != 0) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else {
                        dp[i][j] = 1;
                    }
                }
                else {
                    if (j != 0) {
                        dp[i][j] = dp[i][j - 1];
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
        }

        return dp[s.length() - 1][t.length() - 1] == s.length();
    }
};