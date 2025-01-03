#pragma once
#pragma once
#include <vector>
#include <set>
#include <string>
using namespace std;
class Solution93 {
public:
    vector<string> res;
    vector<int> item;

    inline bool isValid(int sum) {
        return sum >= 0 && sum <= 255;
    }

    void toNext(int begin, int k, string s) {
        if (k == 0) {
            if (begin == s.length()) {
                string ip = "";
                for (int i = 0; i < 4; i++) {
                    ip += to_string(item[i]);
                    ip += '.';
                }
                ip.resize(ip.size() - 1);
                res.push_back(ip);
            }
            return;
        }

        // i 代表结束位置
        for (int i = begin; i < s.length() && i < begin + 3; i++) {
            int sum = 0;
            int j = begin;
            for (; j <= i; j++) {
                sum = sum * 10 + s[j] - '0';
            }
            if (!isValid(sum) || (i != begin && s[begin] == '0')) {
                continue;
            }
            item.push_back(sum);
            toNext(i + 1, k - 1, s);
            item.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        toNext(0, 4, s);
        return res;
    }
};