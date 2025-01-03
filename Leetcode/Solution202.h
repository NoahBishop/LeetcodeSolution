#pragma once
class Solution202 {
public:
    int getNext(int n) {
        int sum = 0;
        while (n != 0) {
            int r = n % 10;
            sum += r * r;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            fast = getNext(getNext(fast));
            slow = getNext(slow);
            if (fast == 1) {
                break;
            }
            if (fast == slow) {
                return false;
            }
        }
        return true;
    }
};