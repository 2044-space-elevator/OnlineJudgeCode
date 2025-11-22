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
vector<ll> _m[15];
ll arr[(int)2e5 + 5], ny[(int)2e5 + 5];
map<ll, ll> ys[15];
int N, M;

ll dpow(ll a, ll b) {
	ll res = 1;
	rep(i, 1, b) {
		res = res * a;
		res %= M;
	}
	return res;
}

ll length(ll num) {
	int res = 0;
	while (num) {
		res++;
		num /= 10;
	}
	return res;
}

main() {
//	int t; cin >> t; while (t--) solve();
// cout << inverse(7, 3);
	cin >> N >> M;
	rep(i, 1, N) {
		cin >> arr[i];
		_m[length(arr[i])].push_back(arr[i]);
	}
	rep(i, 1, 10) {
		ll base = dpow(10, i) % M;
		rep(j, 1, N) {
			ll val = (arr[j] % M * base) % M;
			ys[i][val]++;
		}
	}
	ll ans = 0;
	rep(i, 1, N) {
		int d = length(arr[i]);
		ll r = (-arr[i]) % M;	
		r = (r + M) % M;
		ans += ys[d][r];
	}
	cout << ans << '\n';
	return 0;
}
