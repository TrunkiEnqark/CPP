#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    queue<int> qu;
    while(n--) {
        char type;
        cin >> type;
        switch (type) {
            case 'E': {
                int x;
                cin >> x;
                qu.push(x);
                break;
            } 
            case 'G': {
                if(qu.empty()) cout << -1 << endl;
                    else cout << qu.front() << endl;
                break;
            }
            case 'D': {
                if(qu.empty()) cout << -1 << endl;
                    else { 
                        cout << qu.front() << endl;
                        qu.pop();
                    }
                break;
            }
        }
    }

    for(; !qu.empty(); qu.pop()) cout << qu.front() << ' ';
}