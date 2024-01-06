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

int n, m, arr[105][105], dp[105];

main() {
//	int t; cin >> t; while (t--) solve();
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        memset(dp, 0, sizeof(dp));
        rep(i, 1, n) {
            rep(j, 1, m) {
                cin >> arr[i][j];
            }
        }
        rep(i, 1, n) {
            rrep(j, 1, m) {
                rep(k, 1, m) {
                    if (j >= k) {
                        dp[j] = max(dp[j], dp[j - k] + arr[i][k]);
                    }
                }
            } 
        }
        cout << dp[m] << endl;
    }
	return 0;
}
