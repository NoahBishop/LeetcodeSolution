#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution17 {
public:
    map<int, string> telmap;
    vector<string> res;

    Solution17() {
        telmap[2] = "abc";
        telmap[3] = "def";
        telmap[4] = "ghi";
        telmap[5] = "jkl";
        telmap[6] = "mno";
        telmap[7] = "pqrs";
        telmap[8] = "tuv";
        telmap[9] = "wxyz";
    }

    void toNext(int begin, string& digits, string path) {
        if (begin == digits.length()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < telmap[digits[begin] - '0'].length(); i++) {
            string cur_path = path;
            cur_path[begin] = telmap[digits[begin] - '0'][i];
            toNext(begin + 1, digits, cur_path);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return res;
        }
        string s = "";
        s.resize(digits.length());
        toNext(0, digits, s);
        return res;
    }
};