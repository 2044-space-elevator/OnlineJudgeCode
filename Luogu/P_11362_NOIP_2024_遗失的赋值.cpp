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

const ll mod = 1e9 + 7;
pair<int, int> arr[(int)1e5 + 5];

ll qpow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		ans %= mod;
		a %= mod;
		b >>= 1;
	}
	return ans;
}

void solve() {
	ll n, m, v;
	cin >> n >> m >> v;	
	bool flg = 0;
	rep(i, 1, m) {
		int a, b;
		cin >> a >> b;
		arr[i] = {a, b};
	}
	if (flg) {
		cout << "0\n";
		return;
	}
	sort(arr + 1, arr + m + 1);
	// cout << qpow(2, 2);
	ll init = qpow(v, (arr[1].first - 1) * 2);
	repq(i, 1, m) {
		if (arr[i].first == arr[i + 1].first && arr[i].second != arr[i + 1].second) {
			cout << "0\n";
			return;
		} 
		if (arr[i + 1].first == arr[i].first) continue;
			init = (init * (qpow(v, (arr[i + 1].first - arr[i].first) 
			* 2ll ) - qpow(v, arr[i + 1].first - arr[i].first - 1) 
			* (v - 1ll) % mod + mod) % mod) % mod;
	}
	init = init * qpow(v, 2ll * (n - arr[m].first)) % mod;
	cout << init << '\n';
}


main() {
int t; cin >> t; while (t--) solve();
	return 0;
}
