#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long x, y;
        cin >> x >> y;
        if(x <= y) {
            if(y&1) {
                cout << y*y - x + 1 << endl;
            } else {
                y--;
                cout << y*y + x << endl;
            }
        } else {
            swap(x, y);
            if(y&1) {
                y--;
                cout << y*y + x << endl;
            } else {
                cout << y*y - x + 1 << endl;
            }
        }
    }
}