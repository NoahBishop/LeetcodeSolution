#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution142 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        map<char, int> char_map;
        for (char i = 'a'; i <= 'z'; i++) {
            char_map[i] = 0;
        }

        for (int i = 0; i < s.length(); i++) {
            char_map[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            int times = --char_map[t[i]];
            if (times < 0) {
                return false;
            }
        }
        return true;
    }
};