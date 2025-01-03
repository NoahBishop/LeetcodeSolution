#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution134 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> rem;
        for (int i = 0; i < gas.size(); i++) {
            rem.push_back(gas[i] - cost[i]);
        }

        int begin = 0;
        int iter = 0;
        int sum = 0;
        // ���п�ʼ�ڵ��ù���߳ɹ�����һȦ
        while (begin < rem.size() && !(iter % rem.size() == begin && begin != iter)) {
            sum += rem[iter % rem.size()];
            if (sum >= 0) {
                iter++;
            }
            else {
                iter++;
                begin = iter;
                sum = 0;
            }
        }

        if (begin >= rem.size()) {
            return -1;
        }

        return begin % rem.size();
    }
};