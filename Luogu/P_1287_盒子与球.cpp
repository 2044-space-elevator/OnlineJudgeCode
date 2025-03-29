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


int f[11][11];
main() {
//	int t; cin >> t; while (t--) solve();
  int n, r;
  cin >> n >> r;
  f[0][0] = 1;
  rep(i, 1, n) {
    rep(j, 1, r) {
      f[i][j] = f[i - 1][j - 1] + j * f[i - 1][j];
    }
  }
  rep(i, 1, r) {
    f[n][r] *= i;
  }
  cout << f[n][r];
	return 0;
}
