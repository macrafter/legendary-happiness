#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


struct Node {
    int value;
    struct Node *next;
};

struct Node *list = NULL;


void insert(int value) {
    struct Node *node = new Node;
    node->value = value;

    if (list != NULL)
        node->next = list;
    else
        node->next = NULL;

    list = node;
}

void delete_list_item() {
    if (list != NULL) {
        Node* d = list;
        list = list->next;
        delete d;
    }
}

void print_list() {
    struct Node* tmp = list;

    while (tmp != NULL) {
        cout << tmp->value << endl;
        tmp = tmp->next;
    }
}

int main() {

    insert(10);
    insert(20);
    insert(30);

    print_list();

    cout << "deleting..." << endl;

    delete_list_item();

    print_list();

    cout << "inserting..." << endl;

    for (int i = 0; i < 100000; i++)
        insert(i + 100);

    print_list();
}

