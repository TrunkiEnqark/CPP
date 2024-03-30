#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

map<char, int> trans = {{'C', 1}, {'D', 2}, {'H', 3}, {'S', 4}};
map<int, char> tranS = {{1, 'C'}, {2, 'D'}, {3, 'H'}, {4, 'S'}};

int n;
char tmp;
string str;
vector<pair<pair<int, char>, pair<int, char>>> res;
vector<pair<int, char>> remains;

void print() {
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].first.first << res[i].first.second << ' ' << res[i].second.first << res[i].second.second << '\n';
    }
}

void solve() {
    vector<int> vec[5];
    res.clear();
    remains.clear();
    cin >> n;
    cin >> tmp;
    int highest = trans[tmp];

    for (int i = 1; i <= 2*n; ++i) {
        cin >> str;
        // cout << trans[str[1]] << endl;
        vec[trans[str[1]]].push_back(str[0] - '0');
    }
    // cout << *vec[1].rbegin() << endl;
    for (int i = 1; i <= 4; ++i) {
        sort(vec[i].begin(), vec[i].end());
    }

    for (int i = 1; i <= 4; ++i) {
        if (i != highest) {
            if (vec[i].size() >= 2) for (int j = 0; j + 1 < vec[i].size(); j += 2) {
                res.push_back({{vec[i][j], tranS[i]}, {vec[i][j + 1], tranS[i]}});
            }
            if (vec[i].size() % 2) remains.push_back({*vec[i].rbegin(), tranS[i]});
        }
    }
    if (remains.size() > vec[highest].size()) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    auto i = vec[highest].size() - 1;
    for (auto it : remains) {
        res.push_back({it, {vec[highest][i], tranS[highest]}});
        i--;
    }

    for (int j = 0; j + 1 < vec[highest].size() - remains.size(); j += 2) {
        res.push_back({{vec[highest][j], tranS[highest]}, {vec[highest][j + 1], tranS[highest]}});
    }
    // cout << res.size() << endl;
    if (res.empty()) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    print();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
}