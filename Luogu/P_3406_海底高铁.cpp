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

#define int ll
const int N= 1e5 + 5;
int cf[(int)1e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  int last = 0;
  int tmp;
  while (m--) {
    cin >> tmp;
    if (last != 0) {
      if (tmp > last) {
        cf[last]++, cf[tmp]--;
      } else {
        cf[tmp]++, cf[last]--;
      }
    }
    last = tmp;
  }
  rep(i, 1, n) cf[i] += cf[i - 1];
  ll ans = 0;
  repq(i, 1, n) {
    int A, B, C;
    cin >> A >> B >> C;
    ans += min(cf[i] * B + C, cf[i] * A);
  }
  cout << ans;
	return 0;
}
