#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    stack<char> st;

    for(char ch : s) {
        if(ch == '(') st.push(ch);
        else {
            if(st.empty() || st.top() != '(') {
                cout << "NO";
                return 0;
            }
            st.pop();
        }
    }

    if(st.empty()) cout << "YES";
        else cout << "NO";
}