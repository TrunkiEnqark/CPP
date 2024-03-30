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
const int N = 1e7 + 5;

class BitTrie {
private:
    int trie[N][2], cnt;
public:
    BitTrie() {
        memset(trie, -1, sizeof trie);
        cnt = 0;
    }

    void trieAdd(int n) {
        int u = 0;
        for (int i = 31; i >= 0; --i) {
            int bit_current = (n >> i) & 1;
            if (trie[u][bit_current] == -1) trie[u][bit_current] = ++cnt;
            u = trie[u][bit_current];
        }
    }

    int findMinXor(int prefixXOR) {
        int u = 0, MinXor = 0;
        for (int i = 31; i >= 0; --i) {
            int bit_current = (prefixXOR >> i) & 1;
            if (bit_current == 1) {
                if (trie[u][0] != -1) {
                    u = trie[u][0];
                } else {
                    MinXor |= (1 << i);
                    u = trie[u][1];
                }
            } else {
                if (trie[u][1] != -1) {
                    MinXor |= (1 << i);
                    u = trie[u][1];
                } else {
                    u = trie[u][0];
                }
            }
        }
        return MinXor;
    }
};

BitTrie Trie;

void solve() {
    int n;
    cin >> n;
    int freXor = 0, result = 0;
    Trie = BitTrie();
    Trie.trieAdd(0);
    while (n--) {
        int a;
        cin >> a;
        freXor ^= a;
        result = max(result, (freXor ^ Trie.findMinXor(freXor)));
        Trie.trieAdd(freXor);
    }
    cout << result;
} 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    solve();

    return 0;
}