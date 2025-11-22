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

int cnt = 0;
pair<int, int> P[(int)1e6 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
	stg s;
	cin >> s;
	char lst = '#';
	for (char v : s) {
		if (v == lst) {
			P[cnt].second++;
		} else {
			P[++cnt] = {v - '0', 1};
			lst = v;
		}
	}
	ll ans = 0;
	repq(i, 1, cnt) {
		if (P[i + 1].first - 1 == P[i].first) {
			ans += min(P[i].second, P[i + 1].second);
		}
	}
	cout << ans;
	return 0;
}
