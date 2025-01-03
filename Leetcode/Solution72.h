#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution72 {
public:
    // ����dp[i + 1][j + 1]ΪA��iΪ����Ԫ�ص����к�B��jΪ����Ԫ��ת�����С����
    // ���word1[i] == word2[j], ��ôdp[i + 1][j + 1] = dp[i][j]; �����ò���
    // ���������Ҫ���ӣ�ɾ���������滻
    // ��Ϊ��һ�������� �ȼ��� ��һ��ɾ��, �滻ֻ��Ҫ��dp[i][j]λ�ú�, ʹword1[i] == word2[j]
    // ���� dp[i + 1][j + 1] = min(dp[i][j], dp[i + 1][j] , dp[i][j + 1]) + 1;
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

        for (int i = 1; i < word1.length(); i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i < word2.length(); i++) {
            dp[0][i] = i;
        }

        for (int i = 0; i < word1.length(); i++) {
            for (int j = 0; j < word2.length(); j++) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else {
                    dp[i + 1][j + 1] = min({ dp[i][j], dp[i + 1][j], dp[i][j + 1] }) + 1;
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};