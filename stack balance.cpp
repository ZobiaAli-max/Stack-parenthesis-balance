#include<iostream>
using namespace std;
class Stack {
    private:
        char arr[100];  
        int top;

    public:
        Stack() {
            top = -1;  
        }

        void push(char value) {
            if (top < 99) {  
                top++;
                arr[top] = value;
            } else {
                cout << "Stack Overflow!" << endl;
            }
        }

        char pop() {
            if (top >= 0) {  
                char popValue = arr[top];
                top--;
                return popValue;
            } else {
                return '\0';  
            }
        }

        bool isEmpty() {
            return (top == -1);
        }
};

bool isBalanced(string str) {
    Stack s;  

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = s.pop();  

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return s.isEmpty();
}

int main() {
    string inputStr;
    cout << "Enter a string of parentheses: ";
    cin >> inputStr;

    if (isBalanced(inputStr)) {
        cout << "The parentheses are balanced!" << endl;
    } else {
        cout << "The parentheses are not balanced!" << endl;
    }
}

