#pragma once
#include <string>
#include <memory>
using namespace std;
class Solution383 {
public:
    int cnt[26];

    bool canConstruct(string ransomNote, string magazine) {
        memset(cnt, 0, sizeof(int) * 26);

        for (int i = 0; i < magazine.length(); i++) {
            cnt[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.length(); i++) {
            int times = --cnt[ransomNote[i] - 'a'];

            if (times < 0) {
                return false;
            }
        }
        return true;
    }
};