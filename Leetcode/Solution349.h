#pragma once
#include <vector>
#include <string>
#include <map>
#include <memory>
using namespace std;

class Solution349 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int nums_1[1001], nums_2[1001];
        memset(nums_1, 0, 1001);
        memset(nums_2, 0, 1001);

        for (int i = 0; i < nums1.size(); i++) {
            nums_1[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            nums_2[nums2[i]]++;
        }

        vector<int> res;
        for (int i = 0; i < 1001; i++) {
            if (min(nums_2[i], nums_1[i])) {
                res.push_back(i);
            }
        }
        return res;
    }
};