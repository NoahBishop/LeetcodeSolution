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

class Solution160 {
public:
    int count_extra(ListNode* head) {
        int dis = 0;
        while (head) {
            dis++;
            head = head->next;
        }
        return dis;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* cur_a = headA, * cur_b = headB;
        ListNode* h_a = headA, * h_b = headB;
        while (cur_a && cur_b) {
            cur_a = cur_a->next;
            cur_b = cur_b->next;
        }

        if (cur_b == nullptr) {
            for (int i = 0; i < count_extra(cur_a); i++) {
                h_a = h_a->next;
            }

            while (h_a && h_b) {
                if (h_a == h_b) {
                    return h_a;
                }
                h_a = h_a->next;
                h_b = h_b->next;
            }
        }
        else {
            for (int i = 0; i < count_extra(cur_b); i++) {
                h_b = h_b->next;
            }
            while (h_a && h_b) {
                if (h_a == h_b) {
                    return h_a;
                }
                h_a = h_a->next;
                h_b = h_b->next;
            }
        }
        return nullptr;
    }
};