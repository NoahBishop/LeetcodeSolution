#pragma once
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

class Solution739 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        stack<int> s;
        s.push(0);

        for (int i = 1; i < temperatures.size(); i++) {
            // ��ʱ��iλ�ñȶ���Ԫ�ش�, �ǵ�һ���������Ԫ��
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return res;
    }
};