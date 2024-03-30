#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int s, t, a, b, n, m, apple[N], orange[N];

bool in(int a, int b, int i) {
    return a <= i && i <= b;
}

int main() {
    cin >> s >> t >> a >> b >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> apple[i];
    for(int i = 1; i <= m; ++i) cin >> orange[i];

    int res_apple = 0, res_orange = 0;
    for(int i = 1; i <= n; ++i) 
        res_apple += in(s, t, a + apple[i]);
    for(int i = 1; i <= m; ++i)
        res_orange += in(s, t, b + orange[i]);
    cout << res_apple << '\n' << res_orange;
}