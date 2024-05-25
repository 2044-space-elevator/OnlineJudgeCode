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
#define int ll

void solve() {
	
}

int n, arr[(int)2e3 + 5][(int)2e3 + 5];
int ans = LONG_LONG_MIN;

bool fail(int i, int j) {
	if (i <= n && i >= 1 && j <= n && j >= 1) {
		return true;
	}
	return false;
}

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n;
	rep(i, 1, n) {
		rep(j, 1, n) {
			cin >> arr[i][j];
		}
	}
	rep(i, 1, n) {
		int tmp = 0;
		rep(j, 1, n) {
			tmp += arr[i][j];
		}		
		ans = max(ans, tmp);
		tmp = 0;
		rep(j, 1, n) {
			tmp += arr[j][i];
		}
		ans = max(ans, tmp);
	}
	rep(i, 1, n) {
		int x = i, y = 1, tmp = 0;
		while (fail(x, y)) {
			tmp += arr[x][y];
			x++, y++;
		}
		ans = max(ans, tmp);
		x = 1, y = i, tmp = 0;
		while (fail(x, y)) {
			tmp += arr[x][y];
			x++, y++;
		}
		ans = max(ans, tmp);
	}
	rep(i, 1, n) {
		int x = i, y = n, tmp = 0;
		while (fail(x, y)) {
			tmp += arr[x][y];
			x++, y--;
		}
		ans = max(ans, tmp);
		x = 1, y = i, tmp = 0;
		while (fail(x, y)) {
			tmp += arr[x][y];
			x++, y--;
		}
		ans = max(ans, tmp);
		
	}
	cout << ans;
	return 0;
}
