#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    char a[n];
    int cnt[123];
    memset(cnt, 0, sizeof cnt);
    for(auto &it : a) {
        cin >> it;
        cnt[it]++;
    }
    
    char char_max = 'a';
    for(char i = 'b'; i <= 'z'; ++i) {
        if(cnt[i] > cnt[char_max]) char_max = i;
    }
    cout << char_max;
}