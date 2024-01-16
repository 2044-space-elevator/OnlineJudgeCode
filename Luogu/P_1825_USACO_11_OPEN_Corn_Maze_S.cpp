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
char _map[305][305];
bool vis[305][305];
int n, m, startX, startY, endX, endY;

struct pt {
    int x, y, step;
};

int dxy[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void bfs() { 
    queue<pt> q;
    q.push(pt{startX, startY, 0});
    while (q.size()) {
        pt frt = q.front(); q.pop();
        if (_map[frt.x][frt.y] == '=') {
            cout << frt.step;
            return;
        }
        char c = _map[frt.x][frt.y];
        if (c >= 'A' && c <= 'Z') {
            rep(j, 1, n) {
                rep(k, 1, m) {
                    if (_map[j][k] == _map[frt.x][frt.y] && (j != frt.x || k != frt.y)) {
                        frt.x = j, frt.y = k;
                        goto _;
                    }
                }
            }
        }
        _:;
        repq(i, 0, 4) {
            int dx = frt.x + dxy[i][0], dy = frt.y + dxy[i][1];
            if (dx < 0 || dx > n || dy < 0 || dy > m || vis[dx][dy] || _map[dx][dy] == '#') {
                continue;
            }
            vis[dx][dy] = 1;
            q.push({dx, dy, frt.step + 1});
        }
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, n) {
        rep(j, 1, m) {
            cin >> _map[i][j];
            if (_map[i][j] == '@') {
                startX = i; startY = j;
            } 
        }
    }
    bfs();
	return 0;
}
