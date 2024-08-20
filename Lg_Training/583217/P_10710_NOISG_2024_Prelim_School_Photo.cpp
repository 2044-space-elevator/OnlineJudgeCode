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


int n, s, cnt = 0, r = 1, l = 1, among = 0, ans = INT_MAX;
int isin[(int)1e6 + 5];
pair<int, int> p[(int)1e6 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> s;
  rep(i, 1, n) {
    rep(j, 1, s) {
      cin >> p[++cnt].first;
      p[cnt].second = i;
    }
  }
  sort(p + 1, p + cnt + 1);
  while (l <= r && r <= cnt + 1) {
    if (among < n) {
      among += (++isin[p[r].second] == 1);
      r++;
    } else {
      ans = min(ans, p[r - 1].first - p[l].first);
      among -= (!(--isin[p[l].second]));
      l++;
    }
  } 
  cout << ans;
	return 0;
}
