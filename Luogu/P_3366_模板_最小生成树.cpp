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

const int N = 5005;
int g[N][N], dist[N], n, m;
bool vis[N];
const int INF = 0x3f3f3f3f;

int prim() {
  int ans = 0;
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  rep(i, 1, n) {
    int t = - 1;
    rep(j, 1, n) {
      if (!vis[j] && (t == -1 || dist[j] < dist[t])) {
        t = j;
      }
    }
    if (i && dist[t] == INF) {
      return INF;
    }
    ans += dist[t];
    vis[t] = 1;
    rep(j, 1, n) {
      if (dist[j] > g[t][j] && !vis[j]) {
        dist[j] = g[t][j];
      }
    }
  }
  return ans;

}
main() {
  //  int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  memset(g, 0x3f, sizeof g)
;
  rep(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u][v] = g[v][u] = min(g[u][v], w);
  }
  int res = prim();
  if (res == INF) {
    cout << "orz";
  } else cout << res;
  return 0;
}