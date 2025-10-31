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

int s[10005], t[10005], ans[10005];
bitset<2005> floyd[2005];

main() {
//	int t; cin >> t; while (t--) solve();
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		floyd[u][v] = 1;
	}
	int q;
	cin >> q;
	rep(i, 1, q) {
		cin >> s[i] >> t[i];
		ans[i] = -1;
	}
	rep(k, 1, n) {
		rep(i, 1, n) 
			if (floyd[i][k]) floyd[i] |= floyd[k];
		rep(i, 1, q)
			if (ans[i] == -1 && floyd[s[i]][t[i]])
				ans[i] = max({k, s[i], t[i]});
	}
	rep(i, 1, q)
		cout << ans[i] << '\n';
	return 0;
}
