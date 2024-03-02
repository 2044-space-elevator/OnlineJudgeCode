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

int G[1005][1005];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v;
    cin >> u >> v;
    G[u][v] = G[v][u] = 1;
  }
  rep(i, 1, n) {
    rep(j, 1, n)
      cout << G[i][j] << ' ';
    cout << endl;
  }
  rep(i, 1, n) {
    int cnt = 0;
    rep(j, 1, n) {
      cnt += G[i][j];
    }
    cout << cnt << ' ';
    rep(j, 1, n) {
      if (G[i][j] || G[j][i]) {
        cout << j << ' ';
      }
    }
    cout << endl;
  }
	return 0;
}
