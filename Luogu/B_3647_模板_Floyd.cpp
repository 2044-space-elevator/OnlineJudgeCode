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

int n, m, dis[205][205];

main() {
  //  int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  memset(dis, 63, sizeof dis);
  rep(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    dis[u][v] = dis[v][u] = min(dis[u][v], w);
  }
  rep(k, 1, n) {
    rep(i, 1, n) {
      rep(j, 1, n) {
        if (i == j) {
          dis[i][i] = 0;
        }
        if (dis[i][k] + dis[k][j] < dis[i][j]) {
          dis[i][j] = dis[i][k] + dis[k][j];
        }
      }
    }
  } 
  rep(i, 1, n) {
    rep(j, 1, n) {
      cout << dis[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}