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
	ll X, Y, K;
	cin >> X >> Y >> K;
	ll Xd = X, Yd = Y;
	ll cnt0 = 0, cnt1 = 0;
	ll ans = 0;
	if (X == Y) ans = 0;
	while (X) {
		X /= K;
		cnt0++;
	}
	while (Y) {
		Y /= K;
		cnt1++;
	}
	X = Xd, Y = Yd;
	while (cnt0 > cnt1) {
		X /= K;
		cnt0--;
		ans++;
	}
	while (cnt1 > cnt0) {
		Y /= K;
		cnt1--;
		ans++;
	}
	while (X != Y) {
		X /= K, Y /= K; ans += 2;
	}
	cout << ans << '\n';

}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
