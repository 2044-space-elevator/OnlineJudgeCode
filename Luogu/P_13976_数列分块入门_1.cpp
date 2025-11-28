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
int arr[300005], tag[300005];
int fkl[300005], fkr[300005], fkcnt = 0, n;

int findk(int x) {
	rep(i, 1, fkcnt) {
		if (fkl[i] <= x && x <= fkr[i]) return i;
	}
	return fkcnt;
}

main() {
	cin >> n;
	rep(i, 1, n) cin >> arr[i];
	int cn = 0, BLK = sqrt(n);
	while (cn < n) {
		fkl[++fkcnt] = cn + 1;
		cn += BLK;
		fkr[fkcnt] = min(cn, n);
	}
	if (cn < n)
		fkl[++fkcnt] = cn + 1, fkr[fkcnt] = n;
	while (n--) {
		int typ, l, r, c;
		cin >> typ >> l >> r >> c;
		if (typ == 0) {	
			int lk = findk(l), rk = findk(r);
			rep(i, lk + 1, rk - 1) tag[i] += c;
			rep(i, l, min(r, fkr[lk])) arr[i] += c;
			if (fkl[rk] > l)
				rep(i, fkl[rk], r) arr[i] += c;
		} else {
			ll ans = tag[findk(r)] + arr[r];
			cout << ans << '\n';
		}
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
