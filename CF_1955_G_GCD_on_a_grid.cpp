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

int arr[105][105];
bool flg[105][105];
void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, 1, n) rep(j, 1, m)
		cin >> arr[i][j];
	int limit = __gcd(arr[1][1], arr[n][m]);
	rrep(k, 1, limit) {
		if (limit % k) continue;
		memset(flg, 0, sizeof flg);
		flg[1][1] = 1;
		rep(i, 1, n) {
			rep(j, 1, m) {
				if (i == 1 && j == 1) continue;
				flg[i][j] = flg[i][j - 1] | (__gcd(arr[i][j - 1], arr[i][j]) % k == 0);
				flg[i][j] = flg[i - 1][j] | (__gcd(arr[i - 1][j], arr[i][j]) % k == 0);
			}
		}
		if (flg[n][m]) {
			cout << k << '\n';
			return;
		}
	}	
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
