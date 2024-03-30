#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n[3], a[N];
stack<int> st[3];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n[0] >> n[1] >> n[2];
    for(int k = 0; k < 3; ++k) {
        for(int i = n[k]; i > 0; --i) cin >> a[i];
        st[k].push(a[1]);
        for(int i = 2; i <= n[k]; ++i) 
            st[k].push(st[k].top() + a[i]);
    }

    // 1 + 1 = 2 => always true :D
    while(1 + 1 == 2) {
        if(st[0].empty() || st[1].empty() || st[2].empty()) break;
        int val1 = st[0].top();
        int val2 = st[1].top();
        int val3 = st[2].top();

        if (val1 == val2 && val1 == val3) {
            cout << val1;
            return 0;
        }

        int val_max = max({val1, val2, val3});
        if(val_max == val1) st[0].pop();
        if(val_max == val2) st[1].pop();
        if(val_max == val3) st[2].pop();
    }

    cout << 0;
}