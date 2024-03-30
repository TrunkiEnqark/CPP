#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    int res = 0;
    for (auto ch : s) res += isdigit(ch);
    cout << res;
}