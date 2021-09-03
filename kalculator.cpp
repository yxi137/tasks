#include<iostream>
#include<algorithm>

using namespace std;

int getNum () {
    int a;
    cout << "Enter number ";
    cin >> a;
    return a;
}

typedef int (*arifmeticFcn)(int, int);

char getOperation () {
    char ch;
    do {
        cout << "Enter operation ";
        cin >> ch;
    }
    while ((ch!='+')&&(ch!='-')&&(ch!='*')&&(ch!='/'));
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

arifmeticFcn getArifmeticFch(char ch) {
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

int main () {
    int a = getNum();
    char ch = getOperation();
    int b = getNum();
    arifmeticFcn fcn = getArifmeticFch(ch);
    cout << a << " " << ch << " " << b << " = " << fcn(a,b); 
    return 0;
}