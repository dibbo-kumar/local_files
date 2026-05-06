#include <iostream>
#include <stack>
using namespace std;

int precedent(char ch) {
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

string toPostfix(string exp) {
    stack<char> s;
    string post = "";

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (isdigit(ch)) {
            post += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (s.top() != '(') {
                post += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && precedent(s.top()) >= precedent(ch)) {
                post += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        post += s.top();
        s.pop();
    }
    return post;
}

int evalPostfix(string post) {
    stack<int> s;
    for (int i = 0; i < post.length(); i++) {
        char ch = post[i];
        if (isdigit(ch)) {
            s.push(ch - '0'); 
        }
        else {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            if (ch == '+') s.push(a + b);
            else if (ch == '-') s.push(a - b);
            else if (ch == '*') s.push(a * b);
            else if (ch == '/') s.push(a / b);
        }
    }
    return s.top();
}

int main()
{
    string exp;
    cout << "Enter expression: "; 
    cin >> exp;

    string post = toPostfix(exp);
    cout << "Postfix: " << post << endl;

    cout << "Result: " << evalPostfix(post) << endl;

    return 0;
}