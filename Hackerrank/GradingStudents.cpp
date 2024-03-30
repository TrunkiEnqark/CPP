#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int grade;
        cin >> grade;
        if(grade < 38) cout << grade << endl;
            else {
                int new_grade = (grade / 5 + 1) * 5;
                if(abs(new_grade - grade) < 3) cout << new_grade << endl;
                    else cout << grade << endl;
            }
    }
}