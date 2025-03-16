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

stg str;
ull mod = 1 << 31;
ull has(stg s) {
  ll ans = 0;
  for (char c : s) {
    ans = (114 * ans + c) % mod;
  }
  return ans;
}
ull rs[10005];

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  int cnt = 0;
  rep(i, 1, n) {
    cin >> str;
    rs[++cnt] = has(str);
  }
  sort(rs, rs + cnt + 1);
  cout << unique(rs, rs + cnt + 1) - rs - 1;
	return 0;
}
