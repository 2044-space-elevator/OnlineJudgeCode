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
int n, c;
ll m;
const int N = 5E5 + 5;
int arr[N], mp[N];
ll path[N];

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m >> c;
	rep(i, 1, n) {
		cin >> arr[i];
		mp[i] = arr[i];
	}
	sort(mp + 1, mp + n + 1);
	int cnt = unique(mp + 1, mp + n + 1) - (mp + 1);
	// rep(i, 1, cnt) {
	// 	cout << mp[i] << ' ' ;
	// }
	// cout << endl;
	rep(i, 1, n) {
		arr[i] = lower_bound(mp + 1, mp + cnt + 1, arr[i]) - mp;
		path[arr[i]]++;
	}
	rep(i, 1, cnt) {
		path[i] += path[i - 1];
	}
	int st = lower_bound(mp + 1, mp + cnt + 1, 0) - mp;
	ll ans = 0;
	// cout << cnt;
	rep(i, st, cnt) {
		// path[qw] - path[i - 1] >= C
		ll tmp = 0;
		int ed = lower_bound(path + 1, path + cnt + 1, c + path[i - 1]) - path;
		tmp += path[min(ed, cnt)] - path[i - 1];
		// tmp + path[qw] >= C
		if (ed > cnt) {
			int ed2 = lower_bound(path + 1, path + cnt + 1, c - tmp) - path;
			tmp += path[ed2];
		}
		if (i != st) {
			ans += tmp * (mp[i] - mp[i - 1]);
		}
		else if (i == st) {
			ans += tmp * (mp[i] - mp[i - 1] + m - mp[n]);
		}
			// cout << tmp << endl;
	}
	cout << ans;
	return 0;
}
