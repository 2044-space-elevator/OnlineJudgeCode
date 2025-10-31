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

int n, m, q;
const int N = 1E5 + 5;
int STar_mx[N][20], STbr_mn[N][20], STbr_mx[N][20], STar_mn[N][20];
int STpos_mn[N][20], STneg_mx[N][20];

void ST(int (*dealt)[20], int typ) {
	rep(j, 1, 19) {
		rep(i, 1, n - (1 << j) + 1) {
			if (typ == 0)
				dealt[i][j] = max(dealt[i][j - 1], dealt[i + (1 << (j - 1))][j - 1]);
			else 
				dealt[i][j] = min(dealt[i][j - 1], dealt[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query_mx(int (*dealt)[20], int l, int r) {
	int k = log2(r - l + 1);
	return max(dealt[l][k], dealt[r - (1 << k) + 1][k]);
}

int query_mn(int (*dealt)[20], int l, int r) {
	int k = log2(r - l + 1);
	return min(dealt[l][k], dealt[r - (1 << k) + 1][k]);
}

void solve() {
	cin >> n >> m >> q;
	rep(i, 1, n) {
		int x;
		cin >> x;
		STar_mx[i][0] = STar_mn[i][0] = x;
		if (x >= 0) {
			STpos_mn[i][0] = x;
			STneg_mx[i][0] = -2e9;
		} else {
			STpos_mn[i][0] = 2e9;
			STneg_mx[i][0] = x;
		}
	}
	rep(i, 1, m) {
		int x;
		cin >> x;
		STbr_mn[i][0] = STbr_mx[i][0] = x;
	}
	ST(STar_mx, 0);
	ST(STar_mn, 114514);
	ST(STpos_mn, 114514);
	ST(STneg_mx, 0);
	ST(STbr_mx, 0);
	ST(STbr_mn, 114514);
	while (q--) {
		int la, ra, lb, rb;
		cin >> la >> ra >> lb >> rb;
		if (query_mn(STar_mn, la, ra) >= 0) {
			if (query_mn(STbr_mn, lb, rb) >= 0) {
				ll ans1 = query_mx(STar_mx, la, ra);
				ans1 *= query_mn(STbr_mn, lb, rb);
				cout << ans1 << '\n';
				continue;
			}
			ll ans1 = query_mn(STar_mn, la, ra);
			ans1 *= query_mn(STbr_mn, lb, rb);
			cout << ans1 << '\n';
			continue;
		}
		if (query_mx(STar_mx, la, ra) < 0) {
			if (query_mx(STbr_mx, lb, rb) < 0) {
				ll ans1 = query_mn(STar_mn, la, ra);
				ans1 *= query_mx(STbr_mx, lb, rb);
				cout << ans1 << '\n';
				continue;
			}
			ll ans1 = query_mx(STar_mx, la, ra);
			ans1 *= query_mx(STbr_mx, lb, rb);
			cout << ans1 << '\n';
			continue;
		}
		if (query_mn(STbr_mn, lb, rb) >= 0) {
			ll ans1 = query_mx(STar_mx, la, ra);
			ans1 *= query_mn(STbr_mn, lb, rb);
			cout << ans1 << '\n';
			continue;
		}
		if (query_mx(STbr_mx, lb, rb) < 0) {
			ll ans1 = query_mn(STar_mn, la, ra);
			ans1 *= query_mx(STbr_mx, lb, rb);
			cout << ans1 << '\n';
			continue;
		}
		ll ans1 = query_mn(STpos_mn, la, ra) * (ll)query_mn(STbr_mn, lb, rb);
		ll ans2 = query_mx(STneg_mx, la, ra) * (ll)query_mx(STbr_mx, lb, rb);
		cout << max(ans1, ans2) << '\n';
	}
}


main() {
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
