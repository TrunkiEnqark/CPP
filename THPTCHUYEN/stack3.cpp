#include <bits/stdc++.h>

using namespace std;

map<char, int> mp = {
    {'(', 1},
    {')', -1},
    {'[', 2},
    {']', -2},
    {'{', 3},
    {'}', -3}
};

stack<int> st;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i) {
        int val = mp[s[i]];
        if(val > 0) {
            st.push(val);
        } else {
            if(st.empty()) { cout << "NO"; return 0; }
            int val1 = st.top();
            if((-1) * val == val1) st.pop();
                else {
                    cout << "NO";
                    return 0;
                }
        }
    }

    if(st.empty()) cout << "YES"; 
        else cout << "NO";
}
