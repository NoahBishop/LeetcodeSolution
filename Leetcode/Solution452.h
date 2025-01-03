#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution452 {
public:
    static int mycmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 1) {
            return 1;
        }
        sort(points.begin(), points.end(), mycmp);
        
        int begin = 0;
        int left = points[begin][0], right = points[begin][1];
        int idx = begin + 1;
        int sum = 0;
        while (true) {
            if (begin == points.size() - 1 || idx >= points.size()) {
                sum++;
                break;
            }

            // 最左边位于可以一次性的
            if (left <= points[idx][0] && right >= points[idx][0]) {
                left = max(left, points[idx][0]);
                right = min(right, points[idx][1]);
                idx++;
            }
            else {
                begin = idx;
                left = points[begin][0];
                right = points[begin][1];
                idx++;
                sum++;
            }
        }

        return sum;
    }
};