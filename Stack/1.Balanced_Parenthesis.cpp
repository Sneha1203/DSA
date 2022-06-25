#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool ispar(string s)
{
    stack<char> st;
    bool result = true;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                result = false;
                break;
            }
        }

        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                result = false;
                break;
            }
        }
        
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                result = false;
                break;
            }
        }
    }

    if (!st.empty())
    {
        return false;
    }

    return result;
}


int main() {
    cout << endl << ispar ("{([])}") << endl;
    return 0;
}