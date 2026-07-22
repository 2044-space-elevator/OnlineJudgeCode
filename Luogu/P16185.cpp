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

const int N = 5E6 + 5;
ll dp[N];
ll tmp[10];
int arr[N], n;

ll calc(ll av, ll bv) {
	return av * 2520 / bv;
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> arr[i];
	}
	memset(tmp, 63, sizeof tmp);
	memset(dp, 63, sizeof dp);
	dp[1] = 0;
	tmp[arr[1]] = 0;
	rep(i, 2, n) {
		rrep(j, i - 9, i - 1) {
			if (j < 1) break;
			if (i - j > arr[j]) continue;
			dp[i] = min(dp[i], dp[j] + calc(i - j, arr[j]));
		}
		dp[i] = min(tmp[arr[i]] + 2520, dp[i]);
		tmp[arr[i]] = dp[i];
	}
	ll a = dp[n], b = 2520; ll d = __gcd(a, b);
	a /= d, b /= d;
	cout << a << ' ' << b << '\n';
//	int t; cin >> t; while (t--) solve();
	return 0;
}
