//operator operand operand 

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
    return -1;
}

string prefix (string exp) {
    reverse (exp.begin(), exp.end());
    stack <char> st;
    string result = "";

    for (int i = 0; i < exp.length(); i++) {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) {
            result += exp[i];
        } 
        else if (exp[i] == ')') {
            st.push (exp[i]);
        }
        else if (exp[i] == '(') {
            while (!st.empty() && st.top() != ')') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            while (!st.empty() && precedence (st.top()) >= precedence (exp[i])) {
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

    reverse (result.begin(), result.end());
    return result;
}

int main() {
    string exp = "(a-b/c)*(a/k-l)";
    cout << endl << prefix (exp) << endl;
    return 0;
}