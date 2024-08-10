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

int f[(int)1e5 + 5][32], arr[(int)1e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  std::ios::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  rep(i ,1 , n) { cin >> arr[i]; f[i][0] = arr[i]; }
  rep(j, 1, log2(n)) {
    rep(i, 1, n - (1 << j) + 1) {
      f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << max(f[l][(int)log2(r - l + 1)], f[r - (1 << (int)(log2(r - l + 1))) + 1][(int)log2(r - l + 1)]) << endl;
  }
	return 0;
}
