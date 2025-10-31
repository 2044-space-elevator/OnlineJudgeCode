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
ll n, q;
__int128 jump_len[N], bz[N][32];
const ll mod = 1e9 + 7;
vct<int> one;
ll m;

int query(int l, int r) {
	if (r < l) return 0;
	auto pos = upper_bound(one.begin(), one.end(), r);
	if (pos == one.begin()) return 0;
	pos--;
	return ((*pos > r || *pos < l) ? 0 : *pos);
}


main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m >> q;
	rep(i, 1, n) {
		char c;
		cin >> c;
		if (c == '1') {
			one.push_back(i);
		}
	}
	// cout << query(2, 5) << endl;
	rep(i, 1, n) {
		if (i + m <= n) {
			int to = i + m;
			int qry = query(i + 1, to);
			if (qry) {
				jump_len[i] = qry - i;
			} else {
				jump_len[i] = 1;
			}
		} else if (n < i + m && i + m <= 2 * n) {
			int to = i + m - n;
			int qry1 = query(i + 1, n), qry2 = query(1, to);
			if (qry2) {
				jump_len[i] = qry2 + n - i;
			} else if (qry1) {
				jump_len[i] = qry1 - i;
			} else {
				jump_len[i] = 1;
			}
		} else {
			int to = ((ll)(i - 1ll) + m) % n + 1;
			int qry1 = query(i + 1, n), qry2 = query(1, n), qry3 = query(1, to);
			if (qry3) {
				ll whole = m / n * n;
				jump_len[i] = n - i + qry3 + whole;
			} else if (qry2) {
				ll whole = ((m / n) - 1ll) * n;
				jump_len[i] = whole + qry2 + n - i;
			} else {
				jump_len[i] = 1;
			}
		}
	}
	rep(i, 1, n) {
		bz[i][0] = jump_len[i]; 
	}
	rrep(j, 1, 24) {
		rep(i, 1, n) {
			ll lst_pos = (i + bz[i][j - 1] - 1) % n + 1;
			bz[i][j] = bz[lst_pos][j - 1] + bz[i][j - 1];
		}
	}
	while (q--) {
		ll ans = 0;
		ll sttmp, ktmp;
		cin >> sttmp >> ktmp;
		__int128 st = sttmp, k = ktmp;
		rrep(j, 0, 24) {
			if (k & (1 << j)) {
				// cout << (st - 1) % n + 1 << ' ' << j;
				st = st + bz[(st - 1) % n + 1][j];
			}
		}
		st %= mod;
		while (st) {
			cout << (int)(st % 10);
			st /= 10;
		}
		cout << '\n';
	}
	return 0;
}
