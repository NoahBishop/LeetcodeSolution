#pragma once
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

class Solution496 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> res;

        stack<int> s;
        s.push(nums2[0]);

        for (int i = 1; i < nums2.size(); i++) {
            // 这时候i位置比顶部元素大, 是第一个比他大的元素
            while (!s.empty() && s.top() < nums2[i]) {
                res[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        vector<int> rres(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            if (res.count(nums1[i])) {
                rres[i] = res[nums1[i]];
            }
        }
        return rres;
    }
};