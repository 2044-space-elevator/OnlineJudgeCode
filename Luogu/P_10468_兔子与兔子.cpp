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

#define int ull

const int N = 1E6 + 5;
int sum1[N], power[N];
const int MOD = 1000000000000002493;
void solve() {
  int l, r, a, b; cin >> l >> r >> a >> b;
  bool flg = sum1[r]- sum1[l - 1] * power[r - l + 1]
    == sum1[b] - sum1[a - 1] * power[b - a + 1];
  if (flg) {
    rty
  } else rtn
}

main() {
  stg s;
  cin >> s;
  s = " " + s;
  power[0] = 1;
  repq(i, 1, s.size()) {
    sum1[i] += (sum1[i - 1] * 1331 + s[i]);
    power[i] = 1331 * power[i - 1] ;
  }
	int t; cin >> t; while (t--) solve();
	return 0;
}
