#include <bits/stdc++.h>
#define rty printf("Yes\n");
#define RTY printf("YES\n");
#define rtn printf("No\n");
#define RTN printf("NO\n");
#define rep(v,b,e) for(int v=b;v<=e;v++)
#define repq(v,b,e) for(int v=b;v<e;v++)
#define rrep(v,e,b) for(int v=b;v>=e;v--)
#define rrepq(v,e,b) for(int v=b;v>e;v--)
#define stg string
#define vct vector
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
	
}

char _map[505][505];
char roun[] = " snuke"; int n, m;
bool vis[505][505];

struct single_step {
    int rnber, x, y;
};

int dxy[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void bfs() {
    queue<single_step> q;
    q.push({1, 1, 1});
    vis[1][1] = 1;
    while (q.size()) {
        single_step data = q.front();
        q.pop();
        if (data.x == n && data.y == m) {
            rty;
            return;
        }
        char c = roun[data.rnber % 5 + 1];
        repq(i, 0, 4) {
            int dx = dxy[i][0] + data.x;
            int dy = dxy[i][1] + data.y;
            if (dx <= 0 || dy <= 0 || dx > n || dy > m || vis[dx][dy]) {
                continue;
            }
            if (_map[dx][dy] == c) {
                vis[dx][dy] = 1;
                q.push({data.rnber % 5 + 1, dx, dy});
            }
        }
    }
    rtn;
    return;
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, n) {
        rep(j, 1, m) {
            cin >> _map[i][j];
        }
    }
    if (_map[1][1] != 's') {
        cout << "No\n";
        return 0;
    }
    bfs();
	return 0;
}
