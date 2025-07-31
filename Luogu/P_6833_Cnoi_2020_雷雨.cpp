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

#define int ll
ll dis[3][1005][1005], n, m, arr[1005][1005];
bool vis[1005][1005];

struct node {
    ll x, y, dis;
    bool operator > (const node& b) const {
        return dis > b.dis;
    }
};

priority_queue<node, vector<node>, greater<node> > q;


void dijkstra(int stx, int sty, int typ) {
    rep(i, 1, n) {
        rep(j, 1, m) {
            dis[typ][i][j] = 1e18;
        }
    }
    dis[typ][stx][sty] = arr[stx][sty];
    memset(vis, 0, sizeof vis);
    q.push({stx, sty, arr[stx][sty]});
    while (q.size()) {
        int sx = q.top().x, sy = q.top().y; ll d = q.top().dis; q.pop();
        if (vis[sx][sy]) continue;
        vis[sx][sy] = 1;
        int dxy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        repq(i, 0, 4) {
            int dx = sx + dxy[i][0], dy = sy + dxy[i][1];
            if (dx < 1 || dx > n || dy < 1 || dy > m) continue;
            if (dis[typ][dx][dy] > d + arr[dx][dy]) {
                dis[typ][dx][dy] = d + arr[dx][dy];
                q.push({dx,  dy, dis[typ][dx][dy]});
            }
        }
    }
}

main() {
    cin >> n >> m;
    int a, b, c;
    cin >> a >> b >> c;
    rep(i, 1, n) {
        rep(j, 1, m) {
            cin >> arr[i][j];
        }
    }
    dijkstra(1, a, 0);
    dijkstra(n, b, 1);
    dijkstra(n, c, 2);
    ll ans = 1e18;
    rep(i, 1, n) {
        rep(j, 1, m) {
            ll da = dis[0][i][j];
            ll db = dis[1][i][j] - arr[i][j];
            ll dc = dis[2][i][j] - arr[i][j];
            ans = min(ans, da + db + dc);
        }
    }
    cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
