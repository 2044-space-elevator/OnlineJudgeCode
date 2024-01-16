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

int n, m, A[10005], f[105][105][105];

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, m) {
        cin >> A[i];
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            cin >> f[0][i][j];
        }
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            rep(k, 1, n) {
                f[i][j][k] = min(f[i - 1][j][k], f[i - 1][j][i] + f[i - 1][i][k]);
            }
        }
    }
    int sum = 0;
    rep(i, 2, m) {
        sum += f[n][A[i - 1]][A[i]];
    }
    cout << sum;
	return 0;
}
