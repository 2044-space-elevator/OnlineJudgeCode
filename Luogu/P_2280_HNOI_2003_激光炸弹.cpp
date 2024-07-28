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

const int N = 5E3 + 5;
int n, m;
int _m[(int)5e3 + 5][(int)5e3 + 5], sum[(int)5e3 + 5][(int)5e3 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  int bn = 0, bm = 0;
  rep(i, 1, n) {
    int x, y, v;
    cin >> x >> y >> v;
    x++;
    y++;
    _m[x][y] += v;
    bn = max(bn, x);
    bm = max(bm, y);
  } 
  bn = max(bn, m);
  bm = max(bm, m);
  rep(i, 1, bn) {
    rep(j, 1, bm) {
      sum[i][j] = _m[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }
  int ans = 0;
  rep(i, m, bn) {
    rep(j, m, bm) {
        ans = max(ans, sum[i][j] - sum[i - m][j] - sum[i][j - m] + sum[i - m][j - m]);
    }
  }
  cout << ans;
	return 0;
}
