#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom (stack <int> &st, int value) {
    if (st.empty()) {
        st.push (value);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertAtBottom (st, value);
    st.push (topElement);
}

int main() {
    stack <int> st;
    st.push (1);
    st.push (2);
    st.push (3);
    st.push (4);
    st.push (5);
    st.push (7);
    insertAtBottom (st, 100);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;

}