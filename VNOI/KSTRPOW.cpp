#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    int times;
    cin >> s >> t >> times;
    string tmp;
    while (times--) tmp += s;
    if (tmp == t) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}