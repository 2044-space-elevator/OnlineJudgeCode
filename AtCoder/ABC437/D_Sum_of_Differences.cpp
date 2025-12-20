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

int n, m;
const int N = 3E5 + 5;
const ll mod = 998244353;
ll arr[N], brr[N], pre[N], suf[N];

main() {
	cin >> n >> m;
	rep(i, 1, n) cin >> arr[i];
	rep(i, 1, m) cin >> brr[i];
	sort(brr + 1, brr + m + 1);
	rep(i, 1, m) {
		pre[i] = (pre[i - 1] + brr[i]) % mod;
	}
	rrep(i, 1, m) {
		suf[i] = (suf[i + 1] + brr[i]) % mod;
	}
	ll ans = 0;
	rep(i, 1, n) {
		int pos = upper_bound(brr + 1, brr + m + 1, arr[i]) - brr - 1;
		ans = (ans + arr[i] * pos % mod - pre[pos] + mod) % mod;
		ans = (ans + suf[pos + 1] - arr[i] * (m - pos) % mod + mod) % mod;
	}
	cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
