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

const int N = 3E5 + 5;

pair<ll, ll> lu[N];
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	return (a.first + a.second) < (b.first + b.second);
}

void solve() {
	int n;
	cin >> n;
	rep(i, 1, n) cin >> lu[i].first >> lu[i].second;
	ll sum = 0;
	rep(i, 1, n) sum += lu[i].second;
	sort(lu + 1, lu + n + 1, cmp);
	int ans = 0;
	ll tmp = 0;
	rep(i, 1, n) {
		if (tmp + lu[i].first + lu[i].second <= sum) {
			tmp += lu[i].first + lu[i].second;
			ans++;
		}
	}
	cout << ans << '\n';
}

main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
