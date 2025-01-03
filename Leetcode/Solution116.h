#pragma once
#include <cstdio>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};

#include <vector>
#include <queue>
using namespace std;
class Solution515 {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            int len = q.size();

            for (int i = 0; i < len; i++) {
                if (q.front()->left) {
                    q.push(q.front()->left);
                }

                if (q.front()->right) {
                    q.push(q.front()->right);
                }

                Node* cur = q.front();
                q.pop();
                if (i != len - 1) {
                    cur->next = q.front();
                }
                else {
                    cur->next = NULL;
                }
            }
        }
        return root;
    }
};