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

const int N = 1E6 + 5;
map<int, bool> mp[N];
vct<int> ve[N];

main() {
//	int t; cin >> t; while (t--) solve();
	int n;
	cin >> n;
	rep(i, 1, n) {
		int x, y;
		cin >> x >> y;
		mp[x][y] = 1;
		ve[x].push_back(y);
	}
	ll ans = 0;
	rep(i, 1, 1e6) {
		if (ve[i].size() == 0) continue;
		sort(ve[i].begin(), ve[i].end(), greater<int>());
		repq(j, 0, ve[i].size() ){
			int v = ve[i][j];
			if (mp[i - 1][v + 1]) {
				mp[i - 1][v + 1] = 0;
				continue;
			}
			if (mp[i - 1][v]) {
				mp[i - 1][v] = 0;
				continue;
			}
			if (mp[i - 1][v - 1]) {
				mp[i - 1][v - 1] = 0;
				continue;
			}
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
