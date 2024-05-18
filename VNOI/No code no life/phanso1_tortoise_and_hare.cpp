#include <bits/stdc++.h>

using namespace std; 

long long A, B;

// calculate F(X, Y)
long long F(long long X, long long Y) {
    if (X < Y) X *= 10;
    return X - (X/Y) * Y;
}

long long calc(long long X, long long Y) {
    if (X < Y) X *= 10;
    return X/Y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B;
    cout << A/B << ".";
    A -= (A/B) * B;
    if (A == 0) {
        cout << 0;
        return 0;
    }

    long long tmp = A;

    long long tor = A, hare = A;
    while (true) {
        tor = F(tor, B);
        hare = F(F(hare, B), B);
        if (tor == hare) break;
    }

    // L1
    hare = tmp;
    while (tor != hare) {
        cout << calc(hare, B);
        hare = F(hare, B);
        tor = F(tor, B);
    }

    vector<int> vec;
    while (true) {
        vec.push_back(calc(hare, B));
        hare = F(hare, B);
        if (hare == tor) break;
    }
    if (vec.size() == 1 && vec[0] == 0) return 0;
    cout << "(";
    for (auto it : vec) cout << it;
    cout << ")";

    return 0;
}