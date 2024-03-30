#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    queue<int> qu;
    while(n--) {
        int type;
        cin >> type;
        switch (type) {
            case 1: {
                cout << qu.size() << endl;
                break;
            } 
            case 2: {
                if(!qu.empty()) cout << "NO\n";
                    else cout << "YES\n";
                break;
            }
            case 3: {
                int x;
                cin >> x;
                qu.push(x);
                break;
            }
            case 4: {
                if(!qu.empty()) qu.pop();
                break;
            }
            case 5: {
                if(!qu.empty()) cout << qu.front() << endl;
                    else cout << "-1\n";
                break;
            }
            case 6: {
                if(!qu.empty()) cout << qu.back() << endl;
                    else cout << "-1\n";
                break;
            }
        }
    }
}