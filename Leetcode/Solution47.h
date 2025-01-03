#pragma once
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution47 {
public:
    vector<vector<int>> res;
    vector<int> item;
    // 输入数组已经使用
    int input_numused[8] = { 0 };

    void toNext(int n, vector<int>& nums) {
        if (n == 0) {
            res.push_back(item);
            return;
        }
        // 当前层级使用情况
        int numused[21] = { 0 };
        for (int i = 0; i < nums.size(); i++) {
            if (input_numused[i] == 1) {
                continue;
            }

            if (numused[nums[i] + 10] == 1) {
                continue;
            }
            numused[nums[i] + 10] = 1;
            input_numused[i] = 1;

            item.push_back(nums[i]);
            toNext(n - 1, nums);
            item.pop_back();
            input_numused[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        toNext(nums.size(), nums);
        return res;
    }
};