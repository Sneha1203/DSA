#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) 
    {
        stack <int> st;
        for (int i = 0; i < n; i++) {
            st.push (i);
        }
        
        while (st.size() >= 2) {
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            
            if (M[i][j] == 1) // i knows j
                st.push (j); // j can be celebrity
            else if (M[j][i] == 1) // j knows i
                st.push (i); // j can be celebrity
        }
        
        int cel = st.top();
        st.pop();
        
        for (int i = 0; i < n; i++) {
            if (i != cel) {
                if (M[i][cel] == 0 || M[cel][i] == 1) 
                    return -1;
            }
        }
        return cel;
    }

int main() {
    
}