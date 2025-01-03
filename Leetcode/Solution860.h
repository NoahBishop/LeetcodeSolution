#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution860 {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cash[21] = { 0 };
        int i = 0;
        for (; i < bills.size(); i++) {
            bool success = true;
            switch (bills[i]) {
            case 5:
                cash[5]++;
                break;
            case 10:
                cash[10]++;
                if (cash[5]) {
                    cash[5]--;
                }
                else {
                    success = false;
                }
                break;
            case 20:
                if (cash[5] >= 1 && cash[10] >= 1) {
                    cash[5]--; cash[10]--;
                }
                else if (cash[5] >= 3) {
                    cash[5] -= 3;
                }
                else {
                    success = false;
                }
                break;
            default:
                break;
            }
            if (!success) {
                break;
            }
        }
        return i == bills.size();
    }
};