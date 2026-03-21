#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
}*first = NULL;


// insert at index
void insert(Node *p, int index, int x) {
    Node *t;
    if (index < 0) return;
    t = new Node;
    t->data = x;

    if (index == 0) {
        t->next = first;
        first = t;
    } else {
        for (int i = 0; i < index - 1 && p; i++) {
            p = p->next;
        }
        if (p) {
            t->next = p->next;
            p->next = t;
        }
    }
}

// display list
void display(Node *p) {
    if (p != NULL) {
        cout << p->data << " ";
        display(p->next);
    }
}

// reverse display (Task 1)
void displayReverse(Node* head) {
    if (head == nullptr)
        return;

    displayReverse(head->next);  
    cout << head->data << " ";  
}

// reverse linked list (Task 2)
void reverseList() {
    Node *prev = NULL;
    Node *curr = first;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    first = prev;
}

int main() {

    insert(first, 0, 10);
    insert(first, 1, 20);
    insert(first, 2, 30);
    insert(first, 3, 40);

    cout << "Original Playlist: ";
    display(first);

    cout << "\nReverse Display (without changing list): ";
    displayReverse(first);

    reverseList();

    cout << "\nReversed Playlist (actual): ";
    display(first);

    return 0;
}