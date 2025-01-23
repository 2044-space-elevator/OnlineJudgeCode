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
const int N = 1e3 + 5;
#define int ull
ull arr[N][N];
void solve() {
  int n, m, t;
  cin >> n >> m >> t;
  int tmp;
  rep(i, 1, n) rep(j, 1, m) {
    cin >> tmp;
    arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + tmp;
  }
  ull res = 0;
  while (t--) {
    int u, v, x, y;
    cin >> u >> v >> x >> y;
    ull ans = arr[x][y] - arr[u - 1][y] - arr[x][v - 1] + arr[u - 1][v - 1];
    res ^= ans;
  }
  cout << res << '\n';

}


main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while (t--) solve();
	return 0;
}
