#include <bits/stdc++.h>

using namespace std;

class Queue {
    struct Node {
        int val;
        Node *next;
    };

    int size;
    Node* head;
    Node* tail;

    public:
        Node* CreateNode(int data) {
            Node* tmp = new Node;
            tmp->val = data;
            tmp->next = NULL;
            return tmp;
        }

        bool Empty() { return size == 0; }
        int Size() { return size; }
        int Front() { return head->val; }
        int Back() { return tail->val; }

        void CreateQueue() {
            size = 0;
            head = NULL;
            tail = NULL;
        }

        void Push(int x) {
            Node* node = CreateNode(x);

            size++;
            if(head == NULL) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }

        int Pop() {
            int x = -1;
            if(head != NULL) {
                size--;
                x = head->val;
                head = head->next;
            }
            return x;
        }
};

int main() {
}