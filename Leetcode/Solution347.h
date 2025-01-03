#pragma once
#include <vector>
#include <queue>
using namespace std;

struct Cnt {
    int val;
    int cnts;
};

struct compare {
    bool operator()(Cnt a, Cnt b) {
        return a.cnts > b.cnts;
    }
};

#define half_c 10000

class Solution347 {
public:
    int data[half_c + half_c + 1];

    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::priority_queue<Cnt, std::vector<Cnt>, compare> pq_min;
        memset(data, 0, sizeof(int) * (half_c * 2 + 1));

        for (int i = 0; i < nums.size(); i++) {
            data[nums[i] + half_c]++;
        }

        for (int i = 0; i < half_c + half_c + 1; i++) {
            if (data[i] != 0) {
                Cnt c;
                c.val = i;
                c.cnts = data[i];
                pq_min.push(c);
            }
        }

        while (pq_min.size() > k) {
            pq_min.pop();
        }

        vector<int> res;

        while (!pq_min.empty()) {
            res.push_back(pq_min.top().val);
            pq_min.pop();
        }

        return res;
    }
};