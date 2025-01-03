#pragma once
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
class Solution738 {
public:
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        // flag������Ǹ�ֵ9�����￪ʼ
        // ����Ϊ���Ĭ��ֵ��Ϊ�˷�ֹ�ڶ���forѭ����flagû�б���ֵ�������ִ��
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i]) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};