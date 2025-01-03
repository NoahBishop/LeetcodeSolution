#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution516 {
public:
    // ����dp[i][j]Ϊs���±�[i,j]�ıպ������ڵĻ������г���
    // ���s[i] == s[j], 
    // ���j == i dp[i][j] = 1;
    // ���j = i + 1 dp[i][j] = 2;
    // j - i >= 2 ʱ dp[i][j] = dp[i + 1][j - 1] + 2;
    // ���s[i] != s[j], dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        for (int i = s.length() - 1; i >= 0; i--) { // ����λ��
            for (int j = i; j < s.length(); j++) {     // ��ʼλ��
                if (s[i] == s[j]) {
                    if (j == i) {
                        dp[i][j] = 1;
                    }
                    else if (j == i + 1) {
                        dp[i][j] = 2;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                else {
                    if (j - i == 1) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[0][s.length() - 1];
    }
};