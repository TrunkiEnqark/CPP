#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("txt.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int type;
        cin >> type;
        switch (type) {
            case 1: {
                int x;
                cin >> x;
                st.push(x);
                break;
            }
            case 2: {
                if(!st.empty()) {
                    cout << st.top() << endl;
                    st.pop();
                } else {
                    cout << -1 << endl;
                }
                break;
            }
            case 3: {
                if(!st.empty()) cout << st.top() << endl;
                    else cout << -1 << endl;
                break;
            }
        }
    }

    for(; !st.empty(); st.pop()) cout << st.top() << ' ';
}