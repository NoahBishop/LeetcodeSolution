#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution718 {
public:
    // ����dp[i][j]ΪA��iΪ����Ԫ�ص��������к�B��jΪ����Ԫ�ص��������еĹ�������
    // ���nums1[i] == nums2[j], ��ôdp[i][j] = dp[i - 1][j - 1] + 1;
    // ����dp[i] = 1;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        if (nums1[0] == nums2[0]) {
            dp[0][0] = 1;
        }

        int maxl = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
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
                maxl = max(maxl, dp[i][j]);
            }
        }
        return maxl;
    }
};