#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};


void append(Node*& head, int value) {
    Node* newNode = new Node{value, NULL, NULL};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


void reverseSwap(Node* head) {
    if (!head) return;

    Node* left = head;
    Node* right = head;

    while (right->next)
        right = right->next;

    while (left != right && left->prev != right) {
        swap(left->data, right->data);
        left = left->next;
        right = right->prev;
    }
}



void specialSwap(Node* head) {
    if (!head || !head->next) return;

    Node* left = head->next;
    Node* right = head;

    while (right->next)
        right = right->next;

    right = right->prev; // skip last

    while (left != right && left->prev != right) {
        swap(left->data, right->data);

        if (left->next)
            left = left->next->next;
        if (right->prev)
            right = right->prev->prev;
    }
}


struct Song {
    string name;
    Song* prev;
    Song* next;
};

void addSong(Song*& head, string name) {
    Song* newSong = new Song{name, NULL, NULL};

    if (!head) {
        head = newSong;
        return;
    }

    Song* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newSong;
    newSong->prev = temp;
}

void showPlaylist(Song* head) {
    while (head) {
        cout << head->name << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

struct Item {
    string name;
    Item* next;
};

struct Section {
    string name;
    Item* items;
    Section* next;
};

struct Store {
    string name;
    Section* sections;
    Store* next;
};

void addSection(Store* store, string secName) {
    Section* newSec = new Section{secName, NULL, NULL};

    if (!store->sections) {
        store->sections = newSec;
        return;
    }

    Section* temp = store->sections;
    while (temp->next)
        temp = temp->next;

    temp->next = newSec;
}

void addItem(Store* store, string secName, string itemName) {
    Section* sec = store->sections;

    while (sec && sec->name != secName)
        sec = sec->next;

    if (!sec) return;

    Item* newItem = new Item{itemName, NULL};

    if (!sec->items) {
        sec->items = newItem;
        return;
    }

    Item* temp = sec->items;
    while (temp->next)
        temp = temp->next;

    temp->next = newItem;
}

void displayStore(Store* store) {
    Section* sec = store->sections;

    while (sec) {
        cout << "Section: " << sec->name << endl;

        Item* temp = sec->items;
        while (temp) {
            cout << "  " << temp->name << endl;
            temp = temp->next;
        }
        sec = sec->next;
    }
}


int main() {

    cout << "Task 1: Reverse Swap\n";
    Node* list1 = NULL;
    for (int i = 1; i <= 6; i++)
        append(list1, i);

    display(list1);
    reverseSwap(list1);
    display(list1);


    cout << "\nTask 4: Special Swap\n";
    Node* list2 = NULL;
    for (int i = 1; i <= 9; i++)
        append(list2, i);

    display(list2);
    specialSwap(list2);
    display(list2);


    cout << "\nTask 2: Music Playlist\n";
    Song* playlist = NULL;
    addSong(playlist, "Song A");
    addSong(playlist, "Song B");
    addSong(playlist, "Song C");

    showPlaylist(playlist);



    cout << "\nTask 3: Inventory System\n";
    Store store = {"MyStore", NULL, NULL};

    addSection(&store, "Grocery");
    addSection(&store, "Toys");

    addItem(&store, "Grocery", "Rice");
    addItem(&store, "Grocery", "Milk");
    addItem(&store, "Toys", "Car");

    displayStore(&store);

    return 0;
}