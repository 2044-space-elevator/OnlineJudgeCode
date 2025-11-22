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

char ma[3005], mi[3005];

main() {
//	int t; cin >> t; while (t--) solve();
	int n, m;
	cin >> n >> m;
	rep(i ,1, n) {
		mi[i] = 'z';
		rep(j, 1, m) {
			char t;
			cin >> t;
			ma[i] = max(ma[i], t);
			mi[i] = min(mi[i], t);
		}
	}
	rep(i,1, n ){
		bool flg = 1;
		rep(j ,1, n) {
			if (i == j) continue;
			if (mi[i] >= ma[j]) flg = 0;
		}
		cout << flg;
	}
	return 0;
}
