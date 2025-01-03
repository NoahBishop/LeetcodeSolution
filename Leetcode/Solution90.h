#pragma once
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution90 {
public:
    vector<vector<int>> res;
    vector<int> item;

    void toNext(int left, int right, vector<int>& nums) {
        if (left >= right) {
            return;
        }

        int numused[21] = { 0 };
        for (int i = left; i < right; i++) {
            if (numused[nums[i] + 10] == 1) {
                continue;
            }
            numused[nums[i] + 10] = 1;

            item.push_back(nums[i]);
            res.push_back(item);
            toNext(i + 1, right, nums);
            item.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        res.push_back(item);
        toNext(0, nums.size(), nums);
        return res;
    }
};