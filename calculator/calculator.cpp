#include <iostream>

using namespace std;

int main() {
    char op;
    double num1, num2;

    
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;


    cout << "Choose operation (+, -, *, /): ";
    cin >> op;

    
    switch(op) {
        case '+':
            cout << "Result: " << num1 + num2;
            break;
        case '-':
            cout << "Result: " << num1 - num2;
            break;
        case '*':
            cout << "Result: " << num1 * num2;
            break;
        case '/':
            if (num2 == 0)
                cout << "Error! Division by zero.";
            else
                cout << "Result: " << num1 / num2;
            break;
        default:
            cout << "Invalid operation!";
    }

    return 0;
}
