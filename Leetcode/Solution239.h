#pragma once
#include <vector>
#include <deque>
using namespace std;
class DecreaseQueue {
public:
    DecreaseQueue() {

    }

    void pop(int n) {
        if (!q.empty() && n == q.front()) {
            q.pop_front();
        }
    }

    void push(int n) {
        while (!q.empty() && n > q.back()) {
            q.pop_back();
        }
        q.push_back(n);
    }

    int front() {
        return q.front();
    }

private:
    deque<int> q;
};

class Solution239 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        DecreaseQueue q;
        int cnt = 0;
        vector<int> res(nums.size() - k + 1);

        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
        }

        res[cnt++] = q.front();

        for (int i = k; i < nums.size(); i++) {
            q.pop(nums[i - k]);
            q.push(nums[i]);

            res[cnt++] = q.front();
        }

        return res;
    }
};