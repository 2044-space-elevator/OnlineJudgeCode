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

const int N = 3E5 + 5, bsz = 550;
ll arr[N], bel[N], bl[bsz], br[bsz], lazy[bsz], sum[bsz];
int n;

void update(int l, int r, ll v) {
	// cout << bel[r]  << ' ' << bel[l];
	if (bel[l] == bel[r]) {
		rep(i, l, r) 
			arr[i] += v;
		sum[bel[l]] += (r - l + 1ll) * v;
		return;
	}
	rep(i, l, br[bel[l]])
		arr[i] += v;
	sum[bel[l]] += (br[bel[l]] - l + 1ll) * v;
	rep(i, bl[bel[r]], r) 
		arr[i] += v;
	sum[bel[r]] += (r - bl[bel[r]] + 1ll) * v;
	rep(i, bel[l] + 1, bel[r] - 1) 
		lazy[i] += v;
}

ll query(int l, int r, ll c) {
	ll ans = 0;
	if (bel[l] == bel[r]) {
		rep(i, l, r) {
			ans = ans + (arr[i] + lazy[bel[l]]);
		}
	ans = (ans % (c + 1ll) + c + 1ll) % (c + 1ll);
		return ans;
	}
	rep(i, l, br[bel[l]]) {
		ans = (ans + (arr[i] + lazy[bel[l]]));
	}
	rep(i, bel[l] + 1, bel[r] - 1) {
		ans = ans + sum[i] + lazy[i] * (br[i] - bl[i] + 1ll) ;
	} 
	rep(i, bl[bel[r]], r) {
		ans = ans + (arr[i] + lazy[bel[r]]);
	}
	ans = (ans % (c + 1ll) + c + 1ll) % (c + 1ll);
	return ans;
}


main() {
//	int t; cin >> t; while (t--) solve();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> arr[i];
	int B;
	rep(i, 1, bsz) {
		bl[i] = (i - 1) * bsz + 1;
		br[i] = i * bsz;
		if (br[i] >= n) {
			br[i] = n;
			B = i;
			break;
		}
	}
	rep(i, 1, B) {
		rep(j, bl[i], br[i]) {
			bel[j] = i;
			sum[i] += arr[j];
		}
	}
	rep(i, 1, n) {
		int opt;
		ll l, r, c;
		cin >> opt >> l >> r >> c;
		if (opt == 0) {
			update(l, r, c);
		} else {
			cout << query(l, r, c) << '\n';
		}
	}
	return 0;
}
