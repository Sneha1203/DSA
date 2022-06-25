#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom (stack <int> &st, int element) {

    if (st.empty()) {
        st.push (element);
        return;
    }

    int top_element = st.top();
    st.pop();
    insertAtBottom (st, element);

    st.push (top_element);
}

void reverse (stack <int> &st) {

    if (st.empty()) {
        return;
    }

    int element = st.top();
    st.pop();
    reverse (st);
    insertAtBottom (st, element);
}

void printStack (stack <int> &st) {

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    stack <int> st;
    st.push (1);
    st.push (2);
    st.push (3);
    st.push (4);
    st.push (5);

    reverse (st);
    printStack (st);
    return 0;
}