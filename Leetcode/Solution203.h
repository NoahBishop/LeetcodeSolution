#pragma once
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution203 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* iter = head;
        ListNode* pre = head;
        do {
            if (iter->val == val) {
                if (iter == head) {
                    iter = iter->next;
                    free(head);
                    head = iter;
                    pre = iter;
                }
                else {
                    ListNode* tmp = iter;
                    iter = iter->next;
                    pre->next = iter;
                    free(tmp);
                }
            }
            else {
                pre = iter;
                iter = iter->next;
            }
        } while (iter != nullptr);
        return head;
    }
};