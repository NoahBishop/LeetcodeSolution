#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution435 {
public:
    static int mycmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), mycmp);

        int right = intervals[0][1];
        int sum = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < right) {
                right = min(right, intervals[i][1]);
                sum++;
            }
            else {
                right = intervals[i][1];
            }
        }

        return sum;
    }
};