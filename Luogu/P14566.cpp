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

int arr[100005];

void solve() {
	int mx = 0, mn = 1e9;
	int n;
	cin >> n;
	int ans = 0;
	bool flg = 0;
	rep(i, 1, n) {
		cin >> arr[i];
		if (arr[i] != arr[i + 1] && i < n) flg = 1;
		mn = min(mn, arr[i]);
		mx = max(mx, arr[i]);
	}	
	ans = mx - mn;
	int nxtmx = 0;
	rep(i, 1, n) {
		if (arr[i] < mx && nxtmx < arr[i]) nxtmx = arr[i];
	}
	if (!flg) { cout << "0\n"; return; }
	ans = max(ans, nxtmx);
	cout << ans << '\n';
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
