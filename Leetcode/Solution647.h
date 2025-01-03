#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution647 {
public:
    // ����dp[i][j]Ϊs���±�[i,j]�ıպ������Ƿ�Ϊ�ش�
    // ���s[i] == s[j], ��ôj - i <= 1 ʱ ͬһ��λ�û������λ��
    // dp[i][j] = true;
    // j - i >= 2 ʱ dp[i][j] = dp[i + 1][j - 1];
    // ���s[i] != s[j], һ�����ǻش� dp[i][j] = false;
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), 0));
        int cnt = 0;
        for (int j = 0; j < s.length(); j++) { // ����λ��
            for (int i = 0; i <= j; i++) {     // ��ʼλ��
                if (s[i] == s[j]) {
                    // ͬһ��λ�û������λ��
                    if (j - i <= 1) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                else {
                    dp[i][j] = false;
                }
                if (dp[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};