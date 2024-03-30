#include <bits/stdc++.h>

using namespace std;

bool ok(int x1, int v1, int x2, int v2) {
    for(int i = x1, j = x2, cnt = 0; cnt < 1000000; cnt++, i += v1, j += v2) {
        // cout << i << ' ' << j << endl;
        if(i == j) return true;
    }
    return false;
}

int main() {
    int x1, x2, v1, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    if(ok(x1, v1, x2, v2)) cout << "YES"; else cout << "NO";
}