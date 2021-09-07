#include<iostream>

using namespace std;

struct List {
    int value;
    List* next;
};

List *entList (int num) {
    List *u = nullptr;
   
    cout << "Enter digit ";
    int digit;
    cin >> digit;
    u->value = digit;
    u->next = nullptr;
    List *x = u;
    for (int i = 0; i < num - 1; i++) {
        x->next = new List;
        x = x->next;
        cout << "Enter digit ";
        cin >> digit;
        x->value = digit;
        x->next = nullptr;
    }
    return u;
}

void printList(List *u) {
        while (u) {
        cout << u->value << " ";
        u = u->next;
    }
}

int main () {
    cout << "Enter num ";
    int num;
    cin >> num;
    List *u = entList(num);
    printList(u);
    return 0;
}