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

int V, G, n, T[505], VV[505], GG[505], dp[505][505];

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> V >> G >> n;
    rep(i, 1, n) {
        cin >> T[i] >> VV[i] >> GG[i];
    }
    rep(i, 1, n) {
        rrep(j, VV[i], V) {
            rrep(k, GG[i], G) {
                dp[j][k] = max(dp[j - VV[i]][k - GG[i]] + T[i], dp[j][k]); 
            }
        }
    }
    cout << dp[V][G];
	return 0;
}
