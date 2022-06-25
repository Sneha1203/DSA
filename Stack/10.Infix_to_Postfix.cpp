//operand operand operator

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence (char x) {
    if (x == '^') {
        return 3;
    }
    else if (x == '*' || x == '/') {
        return 2;
    }
    else if (x == '+' || x == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

string postfix (string exp) {

    string result = "";
    stack <char> st;

    for (int i = 0; i < exp.length(); i++) {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) {
            result += exp[i];
        }
        else if (exp[i] == '(') {
            st.push (exp[i]);
        }
        else if (exp[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            while (!st.empty() && precedence (st.top()) > precedence (exp[i])) {
                result += st.top();
                st.pop();
            }
            st.push (exp[i]);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    return result;
}

int main() {
    string exp = "(a-b/c)*(a/k-l)";
    cout << endl << postfix (exp) << endl;
    return 0;
}