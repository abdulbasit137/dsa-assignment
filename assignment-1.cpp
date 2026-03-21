#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
}*first = NULL;


// funtion to insert end
void insert(Node *p, int index, int x) {
    Node *t;
    if (index < 0) return;
    t = new Node;
    t -> data = x;
    if (index == 0) {
        t -> next = first;
        first = t;
    } else {
        for (int i = 0; i < index - 1 && p; i++)
        {
            p = p -> next;
        }
        if (p)
        {
            t -> next = p -> next;
            p -> next = t;
        }
        
    }
}

// function for displaying list 
void rdisplay(struct Node *p) {
    if (p != NULL) {
        cout << p -> data << endl;
        rdisplay(p  -> next);
    }
}

// Function for display in reverse 
void displayReverse(Node* head) {
    if (head == nullptr)
        return;

    displayReverse(head->next);  
    cout << head->data << " ";  
}


int main() {
    // Creating list
    insert(first, 0, 10);
    insert(first, 1, 20);
    insert(first, 2, 30);
    insert(first, 3, 40);

    cout << "Normal Order: ";
    rdisplay(first);

    cout << "\nReverse Order: ";
    displayReverse(first);

    return 0;
}