#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, dist[N + 5][N + 5];
char field[N + 5][N + 5];
bool sign[N + 5][N + 5];

int bfs(int x_start, int y_start) {
    // Khoi tao queue
    queue<pair<int, int> > qu;
    // Khoi tao mang danh dau
    memset(sign, true, sizeof sign);
    memset(dist, 0, sizeof dist);
    // Danh dau va them bo Bessie vao hang doi
    sign[x_start][y_start] = false;
    dist[x_start][y_start] = 0;
    qu.push({x_start, y_start});
    
    while(!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;
        // Gap bai co thi dung lai
        if(field[x][y] == '*') return dist[x][y];
        qu.pop();

        // Loang
        for(int k = 0; k < 4; ++k) {
            // Chuyen trang thai
            int x_next = x + dx[k];
            int y_next = y + dy[k];
            if(1 <= x_next && x_next <= n && 1 <= y_next && y_next <= m && (field[x_next][y_next] == '*' || field[x_next][y_next] == '.') && sign[x_next][y_next]) {
                dist[x_next][y_next] = dist[x][y] + 1; // Quy hoach dong =)))
                // Danh dau da tham
                sign[x_next][y_next] = false;
                qu.push({x_next, y_next});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    int x_Bessie, y_Bessie;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            char ch;
            cin >> ch;
            field[i][j] = ch;
            if(ch == 'C') x_Bessie = i, y_Bessie = j;
        }
    
    cout << bfs(x_Bessie, y_Bessie) << endl;
}