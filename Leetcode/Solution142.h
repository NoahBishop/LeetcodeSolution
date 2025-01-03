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

class Solution142 {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, * fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* idx1 = fast, *idx2 = head;
                while (idx1 != idx2) {
                    idx1 = idx1->next;
                    idx2 = idx2->next;
                }
                return idx1;
            }
        }
        return nullptr;
    }
};