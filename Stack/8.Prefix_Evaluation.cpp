// operator operand operand

#include <iostream>
#include <stack>
#include <math.h>
#include <string>
using namespace std;

int perfixEvaluation (string exp) {
    stack <int> st;
    for (int i = exp.length() - 1; i >= 0; i--) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            st.push (exp[i] - '0');
        } else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (exp[i])
            {
                case ('+'):
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

                default:
                    break;
            }
        }
    }
    return st.top();
}

int main() {
    string exp = "-+7*45+20";
    cout << endl << perfixEvaluation (exp) << endl;
    return 0;
}

