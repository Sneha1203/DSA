char* reverse(char *S, int len)
{
    stack <char> st;
    for (int i = 0; i < len; i++) {
        st.push (S[i]);
    }
    
    int j = 0;
    while (!st.empty()) {
        char x = st.top();
        st.pop();
        S[j] = x;
        j++;
    }
    return S;
}