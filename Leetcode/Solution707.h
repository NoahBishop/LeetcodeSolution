#pragma once
class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) :val(val), next(nullptr) {}
    };

    MyLinkedList():head(nullptr), len(0) {
        head = new LinkedNode(-1);
        head->next = nullptr;
    }

    int get(int index) {
        if (index + 1 > len) {
            return -1;
        }
        LinkedNode * iter = head;
        for (int i = 0; i <= index; i++) {
            iter = iter->next;
        }
        return iter->val;
    }

    void addAtHead(int val) {
        auto tmp = new LinkedNode(val);
        tmp->next = head->next;
        head->next = tmp;
        len++;
    }

    void addAtTail(int val) {
        auto tmp = new LinkedNode(val);
        tmp->next = nullptr;
        LinkedNode* iter = head;
        while (iter->next != nullptr) {
            iter = iter->next;
        }
        iter->next = tmp;
        len++;
    }

    void addAtIndex(int index, int val) {
        if (index > len || index < 0) {
            return;
        }

        LinkedNode* iter = head;
        for (int i = 0; i < index; i++) {
            iter = iter->next;
        }
        auto tmp = new LinkedNode(val);
        tmp->next = iter->next;
        iter->next = tmp;
        len++;
    }

    void deleteAtIndex(int index) {
        if (index >= len || index < 0) {
            return;
        }
        LinkedNode* iter = head;
        for (int i = 0; i < index; i++) {
            iter = iter->next;
        }
        LinkedNode* tmp = iter->next;
        iter->next = tmp->next;
        delete tmp;
        len--;
    }
private:
    LinkedNode* head;
    int len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */