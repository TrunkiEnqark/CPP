#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int k;
    string s;
    cin >> k >> s;
    for (auto ch : s) {
        cout << char ((ch - 'a' - k + 26) % 26 + 'a');
    }

    return 0;
}