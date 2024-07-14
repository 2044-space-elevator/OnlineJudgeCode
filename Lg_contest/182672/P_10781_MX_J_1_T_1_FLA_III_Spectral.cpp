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
	int n; double k;
  cin >> n >> k;
  double con = 1.5;
  if (n == 1) {
    printf("%.1lf\n", k);
  } else {
    printf("%.1lf\n", k * con);
  }
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
