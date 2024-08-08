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

bool vis[205][205];
int n, m;

void dfs(int x, int y) {
  vis[x][y] = 1;
  int dxy[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
  repq(i, 0, 4) {
    int dx = x + dxy[i][0];
    int dy = y + dxy[i][1];
    if (dx > 0 && dx <= n && dy > 0 && dy <= m) {
      if (!vis[dx][dy]) dfs(dx, dy);
    }
  }
}

main() {
  //  int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, n) {
    rep(j, 1, m) {
      char c;
      cin >> c;
      if (c == '#') vis[i][j] = 1;
    }
  }
  int ans = 0;
  rep(i, 1, n) {
    rep(j, 1, m) {
      if (!vis[i][j]) {
        ans++;
        dfs(i, j);
      }
    }
  }
  cout << ans;
  return 0;
}