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
    List *x = stack;
    x->value = sum;
    x->next = nullptr;
    x = x->next;
    x->next = new List;
    return x;
}

int pop (List *stack) {
    while (stack != 0) {
        stack = stack->next;
    }
    return stack->value;
}

int main () {
    int a = getNum();
    int sum = a;
    char ex = '0';
    List *stack = nullptr;
    do {
        char ch = getOperation();
        int b = getNum();
        stack = push(stack, sum);
        arithmeticFcn fcn = getArithmeticFch(ch);
        sum = fcn(sum, b);
        cout << "answer " << sum << endl << "For exit press 'q', undo press 'u', to continue press any key " << endl;
        cin >> ex;

        if (ex == 'u') {
            sum = pop(stack);
            cout << sum << endl;
        }
    }

    while (ex != 'q');
    return 0;
}