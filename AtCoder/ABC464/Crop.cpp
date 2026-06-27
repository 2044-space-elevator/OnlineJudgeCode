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


char ch[55][55];

main() {
//	int t; cin >> t; while (t--) solve();
	int n, m;
	cin >> n >> m;
	rep(i, 1, n) rep(j, 1, m) cin >> ch[i][j];
	int colst = 0;
	rep(i, 1, n) {
		bool flg = 0;
		rep(j, 1, m) {
			if (ch[i][j] == '#') flg = 1;
		}
		if (flg == 1) {
			colst = i;
			break;
		}
	}
	int coled = 0;
	rrep(i, 1, n) {
		bool flg = 0;
		rep(j, 1, m) {
			if (ch[i][j] == '#') flg = 1;
		}
		if (flg == 1) {
			coled = i;
			break;
		}
	}
	int rowst = 0;
	rep(j, 1, m) {
		bool flg = 0;
		rep(i, 1, n) {
			if (ch[i][j] == '#') flg = 1;
		}
		if (flg == 1) {
			rowst = j;
			break;
		}
	}
	int rowed = 0;
	rrep(j, 1, m) {
		bool flg = 0;
		rep(i, 1, n) {
			if (ch[i][j] == '#') flg = 1;
		}
		if (flg == 1) {
			rowed = j;
			break;
		}
	}
	rep(i, colst, coled) {
		rep(j, rowst, rowed) {
			cout << ch[i][j];
		}
		cout << '\n';
	}
	return 0;
}
