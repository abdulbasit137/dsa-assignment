#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Task {
    string name;
    int priority;
    string status;
    Task* next;
};

Task* head = NULL;
Task* current = NULL;

// Create circular list
Node* createCircle(int n) {
    Node *head = new Node{1, NULL};
    Node *last = head;

    for (int i = 2; i <= n; i++) {
        Node* t = new Node{i, NULL};
        last->next = t;
        last = t;
    }
    last->next = head; // make circular
    return head;
}

// Josephus solution
int josephus(int n, int m) {
    Node* head = createCircle(n);
    Node *p = head, *q = NULL;

    while (p->next != p) {
        for (int i = 1; i < m; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
        p = q->next;
    }
    int survivor = p->data;
    delete p;
    return survivor;
}

void addTask(string name, int priority, string status) {
    Task* t = new Task{name, priority, status, NULL};

    if (head == NULL) {
        head = t;
        head->next = head;
    } else {
        Task* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = t;
        t->next = head;
    }
}

void displayTasks() {
    if (head == NULL) return;

    Task* temp = head;
    do {
        cout << temp->name << " | Priority: " << temp->priority 
             << " | Status: " << temp->status << endl;
        temp = temp->next;
    } while (temp != head);
}

void removeTask(string key) {
    if (head == NULL) return;

    Task *curr = head, *prev = NULL;

    do {
        if (curr->name == key) {
            if (curr == head) {
                Task* temp = head;
                while (temp->next != head)
                    temp = temp->next;

                if (head->next == head) {
                    delete head;
                    head = NULL;
                    return;
                }

                temp->next = head->next;
                head = head->next;
                delete curr;
            } else {
                prev->next = curr->next;
                delete curr;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
}


Task* getNextTask() {
    if (head == NULL) return NULL;

    if (current == NULL)
        current = head;

    Task* start = current;

    do {
        if (current->status == "pending") {
            Task* result = current;
            current = current->next;
            return result;
        }
        current = current->next;
    } while (current != start);

    return NULL; // no pending task
}

void updateTask(string name, string newStatus) {
    if (head == NULL) return;

    Task* temp = head;
    do {
        if (temp->name == name) {
            temp->status = newStatus;
            cout << "Updated: " << temp->name 
                 << " -> " << temp->status << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

int main() {

    // Josephus
    cout << "Josephus Survivor: " << josephus(7, 3) << endl;

    // Task system
    addTask("Task1", 1, "pending");
    addTask("Task2", 2, "pending");
    addTask("Task3", 1, "completed");

    cout << "\nAll Tasks:\n";
    displayTasks();

    updateTask("Task2", "completed");

    cout << "\nNext Task: ";
    Task* t = getNextTask();
    if (t)
        cout << t->name << endl;

    removeTask("Task1");

    cout << "\nAfter Removal:\n";
    displayTasks();

    return 0;
}