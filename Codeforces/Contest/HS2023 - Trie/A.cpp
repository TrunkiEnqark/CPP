#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

class Trie {
private:
    int trie[N][26], cnt = 0;
    bool isEnd[N];
public:
    Trie() {
        memset(trie, -1, sizeof trie);
        memset(isEnd, false, sizeof isEnd);
    }

    void addTrie(string s) {
        int u = 0;
        for (int i = 0; i < s.size(); ++i) {
            int nxt = s[i] - 'a';
            if (trie[u][nxt] == -1) trie[u][nxt] = ++cnt;
            u = trie[u][nxt];
        }
        isEnd[u] = true;
    }

    bool findTrie(string s) {
        int u = 0;
        for (int i = 0; i < s.size(); ++i) {
            int nxt = s[i] - 'a';
            if (trie[u][nxt] == -1) return false;
            u = trie[u][nxt];
        }
        return isEnd[u];
    }
};

Trie tree = Trie();

void solve() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        tree.addTrie(s);
    }

    int m;
    cin >> m;
    while(m--) {
        string s;
        cin >> s;
        cout << tree.findTrie(s) << '\n';
    }
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}