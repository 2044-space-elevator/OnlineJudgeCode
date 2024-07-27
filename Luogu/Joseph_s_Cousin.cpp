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

int zs[3502];

main() {
//	int t; cin >> t; while (t--) solve();
  int cnt = 0;
  rep(i, 2, 37000) {
    rep(j, 2, sqrt(i)) {
      if (i % j == 0) {
        goto _;
      }
    }
    cnt++;
    zs[cnt] = i;
    _:;
  }
  // cout << zs[1] << ' ' << zs[2] << ' ' << zs[3] << ' ' << zs[4] << endl;
  int n;
  while (cin >> n) {
    if (!n) {
      return 0;
    }
    int x = 0;
    repq(i, 1, n) {
      x = (x + zs[n - i]) % (i + 1);
    }
    cout << x + 1 << endl;
  }
	return 0;
}
