#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;
    n <<= 1;
    int result = 0;
    while(n--) {
        int a;
        cin >> a;
        pq.push(a);
    } 

    while(!pq.empty()) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        result += min(x, y);
    }
    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
}