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
#define int ll
int n, dp[(int)1e3 + 5];
bool vis[(int)1e3 + 5];
vector<int> primes;

void init() {
    rep(i, 2, 1e3) {
        bool flg = 0;
        rep(j, 2, sqrt(i)) {
            if (i % j == 0) {
                flg = 1;
                break;
            }
        }
        if (!flg) {
            primes.push_back(i);
            vis[i] = 1;
        }
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    init();
    cin >> n;
    dp[0] = 1;
    rep(i, 2, n) {
        if (!vis[i]) {
            continue;
        }
        rep(j, i, n) {
            dp[j] += dp[j - i];
        }
    }
    cout << dp[n];
	return 0;
}
