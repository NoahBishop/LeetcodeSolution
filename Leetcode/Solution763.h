#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Solution763 {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = { 0 };
        // �����ֵ�λ��
        for (size_t i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }
        int split_cnt = 0;

        vector<int> res;
        int cut_pos = 0;
        // ��¼���ֵ���ĸ��������λ��
        for (int i = 0; i < s.length(); i++) {
            cut_pos = max(last[s[i] - 'a'], cut_pos);

            // ����
            if (i == cut_pos) {
                res.push_back(i);
                split_cnt++;
            }
        }

        for (int i = res.size() - 1; i > 0; i--) {
            res[i] = res[i] - res[i - 1];
        }
        res[0]++;
        return res;
    }
};