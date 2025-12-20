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

ll ans = 0;
int n;
const int N = 3e5 + 5;
int per[N];
bool vis[N];

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n;
	rep(i, 1, n) cin >> per[i];
	rep(i, 1, n) {
		if (!vis[i]) {
			int tmp = 0;
			int cur = i;
			while (!vis[cur]) {
				vis[cur] = 1;
				tmp++;
				cur = per[cur];
			}
			ans += tmp * (tmp - 1ll) / 2ll;
		}
	}
	cout << ans;
	return 0;
}
