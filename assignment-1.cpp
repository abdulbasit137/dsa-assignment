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

void removeDuplicates() {
    Node *p = first;

    while (p != NULL) {
        Node *q = p;
        while (q->next != NULL) {
            if (p->data == q->next->data) {
                Node *dup = q->next;
                q->next = dup->next;
                delete dup;
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
}

bool detectLoop() {
    Node *slow = first;
    Node *fast = first;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

Node* findMiddle() {
    Node *slow = first;
    Node *fast = first;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//task 6
void splitEvenOdd(Node* head, Node*& evenHead, Node*& oddHead) {
    Node *evenTail = NULL, *oddTail = NULL;

    while (head != NULL) {
        if (head->data % 2 == 0) {
          
            if (evenHead == NULL) {
                evenHead = evenTail = head;
            } else {
                evenTail->next = head;
                evenTail = head;
            }
        } else {
          
            if (oddHead == NULL) {
                oddHead = oddTail = head;
            } else {
                oddTail->next = head;
                oddTail = head;
            }
        }
        head = head->next;
    }

    //  terminate both lists
    if (evenTail) evenTail->next = NULL;
    if (oddTail) oddTail->next = NULL;
}

//task 7
Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reverseHalves() {
    if (first == NULL || first->next == NULL)
        return;

    Node *slow = first, *fast = first;

    // Find middle (left middle for even)
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secondHalf = slow->next;
    slow->next = NULL;  

    Node *firstHalf = reverse(first);
    secondHalf = reverse(secondHalf);

    first = firstHalf;
    Node *temp = first;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = secondHalf;
}


//task 8
void removeDuplicatesSorted() {
    Node *p = first;

    while (p != NULL && p->next != NULL) {
        if (p->data == p->next->data) {
            Node *dup = p->next;
            p->next = dup->next;
            delete dup;
        } else {
            p = p->next;
        }
    }
}


//task 9
void deleteAll(int key) {
    while (first != NULL && first->data == key) {
        Node *temp = first;
        first = first->next;
        delete temp;
    }

    Node *p = first;

    while (p != NULL && p->next != NULL) {
        if (p->next->data == key) {
            Node *temp = p->next;
            p->next = temp->next;
            delete temp;
        } else {
            p = p->next;
        }
    }
}


//task 10
void pairwiseSwap() {
    Node *p = first;

    while (p != NULL && p->next != NULL) {
        int temp = p->data;
        p->data = p->next->data;
        p->next->data = temp;

        p = p->next->next;
    }
}

int main() {

    // Creating list with duplicates
    insert(first, 0, 10);
    insert(first, 1, 20);
    insert(first, 2, 30);
    insert(first, 3, 20);
    insert(first, 4, 40);
    insert(first, 5, 10);

    cout << "Original List: ";
    display(first);

    // Task 3
    removeDuplicates();
    cout << "\nAfter Removing Duplicates: ";
    display(first);

    // Task 5
    Node* mid = findMiddle();
    cout << "\nMiddle Element: " << mid->data;

    // Task 4 (Loop Test)
    // Manually create loop for testing:
    // first->next->next->next->next = first->next;

    if (detectLoop())
        cout << "\nLoop detected!";
    else
        cout << "\nNo loop found.";

    Node *evenHead = NULL, *oddHead = NULL;

    splitEvenOdd(first, evenHead, oddHead);

    cout << "\nEven List: ";
    display(evenHead);

    cout << "\nOdd List: ";
    display(oddHead);    

    //task 9 test
    deleteAll(20);
    cout << "\nAfter deleting 20: ";
    display(first);

    //task 10 test
    pairwiseSwap();
    cout << "\nAfter pairwise swap: ";
    display(first);

    return 0;
}