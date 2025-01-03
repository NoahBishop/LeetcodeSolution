#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution1143 {
public:
    // ����dp[i][j]ΪA��iΪ����Ԫ�ص����к�B��jΪ����Ԫ�ص����еĹ�������
    // ���nums1[i] == nums2[j], ��ôdp[i][j] = dp[i - 1][j - 1] + 1;
    // ����dp[i] = max(dp[i - 1][j], dp[i][j - 1]);   
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), 0));

        int maxl = 0;
        for (int i = 0; i < text1.length(); i++) {
            for (int j = 0; j < text2.length(); j++) {
                if (text1[i] == text2[j]) {
                    if (i == 0) {
                        dp[i][j] = 1;
                    }
                    else if (j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                }
                else {
                    if (i == 0 && j == 0) {
                        dp[i][j] = 0;
                    }else if (i == 0 && j != 0) {
                        dp[i][j] = max(0, dp[i][j - 1]);
                    }
                    else if (j == 0 && 1 != 0) {
                        dp[i][j] = max(dp[i - 1][j], 0);
                    }
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
                maxl = max(maxl, dp[i][j]);
            }
        }
        return maxl;
    }
};