#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution115 {
public:
    // ����dp[i][j]ΪA��iΪ����Ԫ�ص������г���B��jΪ����Ԫ�ص��������еĴ���
    // ���s[i] == t[j], ��ô����ѡ�����Ԫ��ƥ�� dp[i][j] += dp[i - 1][j - 1]
    // Ҳ���Բ������Ԫ��ƥ�� dp[i][j] += dp[i - 1][j];
    // ���s[i] != t[j], dp[i][j] = dp[i - 1][j];

    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>> dp(s.length(), vector<unsigned long long>(t.length(), 0));
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                if (s[i] == t[j]) {
                    if (i != 0 && j != 0) {
                        dp[i][j] += dp[i - 1][j - 1];
                        dp[i][j] += dp[i - 1][j];
                    }
                    else if (i != 0 && j == 0) {
                        dp[i][j] += dp[i - 1][j];
                        dp[i][j] += 1;
                    }
                    else if (i == 0 && j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        // i == 0, j != 0
                        // ��ʱ�����ù�ȥƥ��ļ���ʹ�ã������� 0
                    }
                }
                else {
                    if (i != 0) {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[s.length() - 1][t.length() - 1];
    }
};