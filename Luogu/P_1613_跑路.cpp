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

int n, m;
int floyd[55][55];
bool gh[65][55][55];

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m;
	memset(floyd, 0x3f, sizeof floyd);
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		gh[0][u][v] = floyd[u][v] = 1;
	}
	rep(k, 1, 64) {
		rep(l, 1, n) {
			rep(i, 1, n) {
				rep(j, 1, n) {
					gh[k][i][j] |= (gh[k - 1][i][l] & gh[k - 1][l][j]);
					if (gh[k][i][j]) floyd[i][j] = 1;
				}

			}
		}
	}
	rep(k, 1, n) {
		rep(i, 1, n) {
			rep(j, 1, n) {
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}
	cout << floyd[1][n];
	return 0;
}
