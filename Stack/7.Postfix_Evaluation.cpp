//operand operand operator

#include <iostream>
#include <stack>
#include <math.h>
#include <string>
using namespace std;

int postfixEvaluation (string exp) {
    stack <int> st;
    for (int i = 0; i < exp.length(); i++) {
        if (exp [i] >= '0' && exp [i] <= '9') {
            st.push (exp [i] - '0');
        } else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (exp [i]) {
                case ('+') :
                    st.push (op1 + op2);
                    break;
                case ('-'):
                    st.push (op1 - op2);
                    break;
                case ('*'):
                    st.push (op1 * op2);
                    break;
                case ('/'):
                    st.push (op1 / op2);
                    break;
                case ('^'):
                    st.push (pow (op1, op2));
                    break;    
            }
        }
    }
    
    return st.top();
}

int main() {
    string exp = "46+2/5*7+";
    cout << endl << postfixEvaluation (exp) << endl;
    return 0;
}