#pragma once
#include <vector>
#include <set>
#include <string>
using namespace std;
class Solution131 {
public:
    vector<vector<string>> res;
    vector<string> item;

    bool isPalin(int begin, int end, string s) {
        while (begin < end) {
            if (s[begin] != s[end]) {
                return false;
            }
            begin++; end--;
        }

        return true;
    }

    void toNext(int begin, string s) {
        if (begin == s.length()) {
            if (!item.empty()) {
                res.push_back(item);
            }
            return;
        }

        for (int i = begin; i < s.length(); i++) {
            if (isPalin(begin, i, s)) {
                string pl = string(s.begin() + begin, s.begin() + i + 1);
                item.push_back(pl);
                toNext(i + 1, s);
                item.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        toNext(0, s);
        return res;
    }
};