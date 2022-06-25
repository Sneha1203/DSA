#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverseSentence (string sentence) {
    stack <string> st;
    for (int i = 0; i < sentence.length(); i++) {
        string words = "";
        while (sentence[i] != ' ' && i < sentence.length()) {
            words += sentence[i];
            i++;
        } 
        st.push (words);
    }

    cout << "Reversed sentence is: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    string str;
    cout << "Enter a sentence: ";
    getline (cin, str);
    reverseSentence (str);
    return 0;
}