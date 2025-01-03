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

class Solution24 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* newhead = new ListNode(-1, head);
        ListNode* iter = newhead;
        ListNode* first = nullptr;
        ListNode* second = nullptr;
        while (iter->next != nullptr && iter->next->next != nullptr) {
            first = iter->next;
            second = iter->next->next;
            first->next = second->next;
            second->next = first;
            iter->next = second;
            iter = first;
        }
        return newhead->next;
    }
};