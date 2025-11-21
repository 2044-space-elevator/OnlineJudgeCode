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

const int N = 2e5 + 5;
ll tree[N];
ll arr[N], brr[N];
int n, q;

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> q;
	while (q--) {
		int a; ll b;
		cin >> a >> b;
		if (a >= 2) {
			arr[a - 1] -= b;
			if (arr[a - 1] > brr[a - 1]) {
				brr[a - 1] = arr[a - 1];
			}
		} if (a < n) {
			arr[a] += b;
			if (arr[a] > brr[a]) {
				brr[a] = arr[a];
			}
		}
	}
	ll ans = n;
	repq(i, 1, n) {
		ans += max(1ll, brr[i] + 1) * (n - i);
	}
	cout << ans << '\n';
	return 0;
}
