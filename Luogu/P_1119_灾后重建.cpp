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

int n, m, k;
int day[205], q, f[205][205][205];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  repq(i, 0, n) {
    cin >> day[i];
  }
  memset(f, 63, sizeof f);
  repq(i, 0, n) {
    f[0][i][i] = 0;
  }
  rep(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    f[0][u][v] = f[0][v][u] = w;
  }
  repq(i, 0, n)
    repq(j, 0, n)
      f[0][i][j] = min(f[0][i][j], f[0][i][0] + f[0][0][j]);
  repq(i, 1, n) {
    repq(j, 0, n) {
        repq(k, 0, n) {
            f[i][j][k] = min(f[i - 1][j][k], f[i - 1][j][i] + f[i - 1][i][k]);
        }
    }
  }
  cin >> q;
  while (q--) {
    int x, y, t; cin >> x >> y >> t;
    int index = upper_bound(day, day + n, t) - day - 1;
    if (index < x || index < y || f[index][x][y] >= f[n + 1][n +1][n + 1]) {
      cout << "-1\n";
      continue;
    }
    cout << f[index][x][y] << endl;
  }
	return 0;
}
