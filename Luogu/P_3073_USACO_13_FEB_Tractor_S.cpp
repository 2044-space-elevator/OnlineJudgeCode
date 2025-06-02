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

int G[505][505];
bool vis[505][505];
int n;

queue<pair<int, int> > q;

bool bfs(int D) {
    int cnt = 1;
    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        int dxy[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        if (cnt * 2 >= n * n) {
            return 1;
        }
        repq(i, 0, 4) {
            int dx= dxy[i][0] + x;
            int dy = dxy[i][1] + y;
            if (dx < 1 || dx > n || dy < 1 || dy > n || vis[dx][dy]) {
                continue;
            }
            if (abs((G[dx][dy] - G[x][y])) <= D) {
                q.push({dx, dy});
                cnt++;
                vis[dx][dy] = 1;
            }
        }
    }
    return 0;
}

bool check(int D) {
    memset(vis, 0, sizeof vis);
    rep(i, 1, n) {
        rep(j, 1, n) {
            if (!vis[i][j]) {
                while (q.size()) q.pop();
                vis[i][j] = 1;
                q.push({i, j});
                if (bfs(D)) return 1;
            }
        }
    }
    return 0;
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    rep(i, 1, n) {
        rep(j, 1, n) {
            cin >> G[i][j];
        }
    }
    int l = 1, r = 1e6;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << l;
	return 0;
}
