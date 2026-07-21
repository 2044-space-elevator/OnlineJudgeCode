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

ull has[6][2005];
const ull B = 173;
ull bpo[2005];
int n;
stg s[2005];

ull get(int now, int l, int r) {
	return has[now][r] - 1ull * has[now][l - 1] * bpo[r - l + 1];
}
map<int, ull> mp[6];

bool check(int len) {
	rep(i, 2, n) {
		mp[i].clear();
		rep(j, 1, s[i].size() - len + 1) {
			mp[i][(ull)get(i, j, j + len - 1)] = 1;
		}
	}
	rep(j, 1, s[1].size() - len + 1) {
		bool flg = 1;
		rep(i, 2, n) {
			if (!mp[i][(ull)get(1, j, j + len - 1)]) {
				flg = 0;
				continue;
			}
		}
		if (flg) return 1;
	}	
	return 0;

}

main() {
	bpo[0] = 1;
	rep(i, 1, 2000) {
		bpo[i] = bpo[i - 1] * B;
	}
	cin >> n;
	int  r = 2000;
	rep(i, 1, n) {
		cin >> s[i];
		r = min(r, (int)s[i].size());
		rep(j, 1, s[i].size()) {
			has[i][j] = has[i][j - 1] * B + s[i][j - 1] - 'a';
		}
	}
	int l = 0, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << '\n';
//	int t; cin >> t; while (t--) solve();
	return 0;
}
