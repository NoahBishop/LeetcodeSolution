#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution56 {
public:
    static int mycmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        list<vector<int>> res;
        sort(intervals.begin(), intervals.end(), mycmp);

        int left = intervals[0][0];
        int right = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= right) {
                right = max(right, intervals[i][1]);
            }
            else {
                vector<int> tmp = { left , right };
                res.push_back(tmp);
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        vector<int> tmp = { left , right };
        res.push_back(tmp);
        return vector<vector<int>>(res.begin(), res.end());
    }
};