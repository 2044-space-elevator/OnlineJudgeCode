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

vct<int> pos[505];
int n, m, p, q;

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m >> p >> q;
  rep(i, 1, p) {
    int x, y;
    cin >> x >> y;
    pos[x].push_back(y);
  }
  rep(i, 1, n){
    sort(pos[i].begin(), pos[i].end());
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    int ans = INT_MAX;
    rep(dx, 0, 500) {
      if (x + dx > n) break;
      if (pos[x + dx].empty()) continue;
      vector<int>::iterator it = lower_bound(pos[x + dx].begin(), pos[x + dx].end(), y);
      vector<int>::iterator it2 = it - 1;
      if (it != pos[x + dx].end()) {
        ans = min(ans, abs((*it) - y) + dx);
      }
      if (it != pos[x + dx].begin()) {
        ans = min(ans, abs((*it2) - y) + dx);
      }
    }
    rep(dx, 0, 500) {
      if (x - dx < 1) break;
      if (pos[x - dx].empty()) continue;
      vector<int>::iterator it = lower_bound(pos[x - dx].begin(), pos[x - dx].end(), y);
      vector<int>::iterator it2 = it - 1;
      if (it != pos[x - dx].end()) {
        ans = min(ans, abs((*it) - y) + dx);
      }
      if (it != pos[x - dx].begin()) {
        ans = min(ans, abs((*it2) - y) + dx);
      }
    }
    cout << ans << endl;
  }
	return 0;
}
