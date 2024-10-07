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

const int N = 2E4 + 5;
int n;
pair<int, int> xy[N];

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) cin >> xy[i].first >> xy[i].second;
  sort(xy + 1, xy + n + 1, cmp);
  pair<double, double> tmp = {abs(xy[1].first + xy[n].first) / 2.0, abs(xy[1].second + xy[n].second) / 2.0};
  rep(i, 2, n / 2) {
    pair<double, double> t = {abs(xy[i].first + xy[n - i + 1].first) / 2.0, abs(xy[i].second + xy[n - i + 1].second) / 2.0};
    if (t != tmp) {
      cout << "This is a dangerous situation!";
      return 0;
    }
  }
  printf("V.I.P. should stay at (%.1lf,%.1lf).", tmp.first, tmp.second);
	return 0;
}
