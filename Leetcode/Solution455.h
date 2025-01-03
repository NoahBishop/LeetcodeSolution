#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution455 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int idx = 0, i = 0;
        while (i < g.size() && idx < s.size()) {
            if (idx < s.size() && s[idx] < g[i]) {
                idx++;
                continue;
            }
            idx++;
            i++;
        }

        return i;
    }
};