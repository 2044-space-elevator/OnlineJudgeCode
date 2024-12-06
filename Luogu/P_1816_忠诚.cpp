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

const int N = 1e5 + 5;
int n, m, ma[N][64], mn[N][64];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  memset(mn, 127, sizeof mn);
  rep(i, 1, n) { cin >> ma[i][0]; mn[i][0] = ma[i][0];}
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      ma[i][j] = max(ma[i][j - 1], ma[i + (1 << j - 1)][j - 1]);
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    int d = log2(r - l + 1);
    int res2 = min(mn[l][d], mn[r - (1 << d) + 1][d]);
    cout << res2 << ' ';
  }
	return 0;
}