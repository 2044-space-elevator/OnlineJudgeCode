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

int grid[100][100];

main() {
//	int t; cin >> t; while (t--) solve();
	int n;
	cin >> n;
	grid[0][(n - 1) / 2] = 1;
	int lstx = 0, lsty = (n - 1) / 2;
	rep(i, 1, n * n - 1) {
		if (!grid[(lstx - 1 + n) % n][(lsty + 1) % n]) {
			grid[(lstx - 1 + n) % n][(lsty + 1) % n] = i + 1;
			lstx = (lstx - 1 + n) % n, lsty = (lsty + 1) % n;
			continue;
		}
		grid[(lstx + 1) % n][lsty] = i + 1;
		lstx = (lstx + 1) % n;
	}
	repq(i, 0, n) {
	repq(j, 0, n) cout << grid[i][j] << ' ' ;
		cout << '\n';
	}
	return 0;
}
