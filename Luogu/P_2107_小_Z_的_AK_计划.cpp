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
const int N = 1E5 + 5;
pair<ll, ll> jf[N];
typedef pair<ll, ll> pll;
priority_queue<pll> q;
ll now, cur, ans;


main() {
	ll n, m;
	cin >> n >> m;
	rep(i ,1, n) {
		cin >> jf[i].first >> jf[i].second;
	}
	sort(jf + 1, jf + n + 1);
	rep(i, 1, n) {
		now += jf[i].first - jf[i - 1].first;
		q.push({jf[i].second, jf[i].first});
		cur++;
		now += jf[i].second;
		if (now > m) {
			while (now > m && q.size()) {
				cur--;
				now -= q.top().first;
				q.pop();
			}
		}
		if (now > m) {
			break;
		}
		ans = max(ans, cur);
	}
	cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
