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

const int N = 3E5 + 5;
int cnt[N];
vector<pair<int, int> > changes[N];

main() {
	int n, m;
	cin >> n >> m;
	rep(i, 1, n) {
		int a, d, b;
		cin >> a >> d >> b;
		if (d == 1) {
			cnt[b]++;
			continue;
		}
		cnt[a]++;
		if (a == b) continue;
		changes[d].push_back({a, b});
	}
	int ans = 0;
	rep(i, 1, n) {
		if (cnt[i]) {
			ans++;
		}
	}
	rep(i, 1, m) {
		for (auto chan : changes[i]) {
			cnt[chan.first]--;
			cnt[chan.second]++;
			if (cnt[chan.first] == 0) ans--;
			if (cnt[chan.second] == 1) ans++;
		}
		cout << ans << '\n' ;
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
