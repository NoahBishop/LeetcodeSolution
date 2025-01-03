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

class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = new ListNode();
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = newhead->next;
            newhead->next = tmp;
        }
        return newhead->next;
    }
};