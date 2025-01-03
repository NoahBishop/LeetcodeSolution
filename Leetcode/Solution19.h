#pragma once
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newhead = new ListNode(-1, head);
        ListNode* slow = newhead, * fast = newhead;
        for (int i = 0; i < n + 1; i++) {
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;

        return newhead->next;
    }
};