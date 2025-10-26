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

const int N = 2E5 + 5;
int arr[N];



main() {
//	int t; cin >> t; while (t--) solve();
	int n;
	cin >> n;
	// ll ans = 0;
	rep(i, 1, n) {
		int x;
		cin >> x;
		arr[x]++;
	}
	ll ans = 0;
	rep(i, 1, n) {
		ans += (n - arr[i]) * arr[i] * (arr[i] - 1ll) / 2ll;
	}
	cout << ans;
	return 0;
}
