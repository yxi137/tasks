#include<iostream>
#include<algorithm>

using namespace std;

struct List {
    int value;
    List *next;
};

int getNum () {
    int a;
    cout << "Enter number ";
    cin >> a;
    return a;
}

typedef int (*arithmeticFcn)(int, int);

char getOperation () {
    char ch;
    do {
        cout << "Enter operation ";
        cin >> ch;
    }
    while ((ch != '+') && (ch != '-') && (ch != '*') && (ch != '/'));
    return ch;
}

int add (int a, int b) {
    return a+b;
}

int substract (int a, int b) {
    return a-b;
}

int multiply (int a, int b) {
    return a*b;
}

int divide (int a, int b) {
    return a/b;
}

arithmeticFcn getArithmeticFch(char ch) {
    switch (ch) {
        default :
        case '+' : 
            return add;
        case '-' : 
            return substract;
        case '*' : 
            return multiply;
        case '/' : 
            return divide;

    }  
}

List *push (List *stack, int sum) {
    List *newHead = nullptr;
    newHead = new List;
    newHead->next = stack;
    newHead->value = sum;
    return newHead;
}

int pop (List *stack) {
    if (stack->next == nullptr) {
        return 0;
    }
    int sum = stack->value;
    delete stack;
    return sum;
}

int main () {
    int a = getNum();
    int sum = a;
    char ex = '0';
    List *stack = nullptr;
    stack = new List;
    stack->next = nullptr;
    List *x = nullptr;
    x = new List;
    x->next = nullptr;
    do {
        char ch = getOperation();
        int b = getNum();
        stack = push(stack, sum);
        arithmeticFcn fcn = getArithmeticFch(ch);
        sum = fcn(sum, b);
        cout << "answer " << sum << endl << "For exit press 'q', undo press 'u', to continue press any key " << endl;
        cin >> ex;

        if (ex == 'u') {
            while (ex == 'u') {
                x = stack->next;
                sum = pop(stack);
                stack = x;
                cout << "answer " << sum << endl << "For exit press 'q', undo press 'u', to continue press any key " << endl;
                cin >> ex;
            }
        }
    }

    while (ex != 'q');
    return 0;
}