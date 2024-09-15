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

bool c[(int)2e3 + 10][(int)2e3 + 10];

void solve() {
  memset(c, 0, sizeof(c));
  int n, m, k;
  cin >> n >> m >> k;
  rep(i, 1, m) {
    c[1][i] = 1;
    k--;
    if (k >= 1) {
      break;
    }
    if (k == 0) {
      goto res;
    }
  }
  rep(i, 1, m) {
    c[2][i] = 1;
    k--;
    if (k == 0) goto res;
  }
  res:;
  rep(i, 1, n) {
    rep(j, 1, m) {
      if (c[i][j] == 0) cout << ".";
      else cout << "S";
    }
    cout << "\n";
  }
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
