#include <iostream>
using namespace std;

int n, m;
char map[26][26];
int ans = 1;
bool vis[1000];

int step = 0;

int dxy[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int x, int y) {
    ans = max(ans, step);
    for (int i = 0; i < 4; i++) {
        int dx = x + dxy[i][0];
        int dy = y + dxy[i][1];
        if (dx < 1 || dy < 1 || dx > n || dy > m || vis[map[dx][dy]]) {
            continue;
        }
        vis[map[dx][dy]] = 1;
        step++;
        dfs(dx, dy);
        step--;
        vis[map[dx][dy]] = 0;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    step = 1;
    vis[map[1][1]] = 1; 
    dfs(1, 1);
    cout << ans << endl;
}