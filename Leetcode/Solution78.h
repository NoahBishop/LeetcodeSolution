#pragma once
#include <vector>
#include <set>
#include <string>
using namespace std;
class Solution78 {
public:
    vector<vector<int>> res;
    vector<int> item;

    void toNext(int left, int right, vector<int>& nums) {
        if (left >= right) {
            return;
        }

        for (int i = left; i < right; i++) {
            item.push_back(nums[i]);
            res.push_back(item);
            toNext(i + 1, right, nums);
            item.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back(item);
        toNext(0, nums.size(), nums);
        return res;
    }
};