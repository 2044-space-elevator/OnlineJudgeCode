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
pair<int, int> sm[5005];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> m >> n;
  rep(i, 1, n) {
    cin >> sm[i].first >> sm[i].second;
  }
  sort(sm + 1, sm + n + 1);
  int cnt = 0;
  rep(i, 1, n) {
    if (m <= sm[i].second) {
      cnt += m * sm[i].first;
      cout << cnt;
      return 0;
    }
    cnt += sm[i].second * sm[i].first;
    m -= sm[i].second;
  }
  cout << cnt;
	return 0;
}
