#pragma once
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution46 {
public:
    vector<vector<int>> res;
    vector<int> item;
    int numused[21] = { 0 };

    void toNext(int n, vector<int>& nums) {
        if (n == 0) {
            res.push_back(item);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (numused[nums[i] + 10] == 1) {
                continue;
            }
            

            item.push_back(nums[i]);
            numused[nums[i] + 10] = 1;
            toNext(n - 1, nums);
            numused[nums[i] + 10] = 0;
            item.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        toNext(nums.size(), nums);
        return res;
    }
};