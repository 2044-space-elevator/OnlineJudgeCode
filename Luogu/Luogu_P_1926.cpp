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

const int N = 155;
int dp[N], n, m, k, r, probT[N], homT[N], homS[N];

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m >> k >> r;
    rep(i, 1, n) cin >> probT[i];
    rep(i, 1, m) cin >> homT[i];
    rep(i, 1, m) cin >> homS[i];
    rep(i, 1, m) {
        rrep(j, homT[i], r) {
            dp[j] = 
            max(
                dp[j], 
                dp[j - homT[i]] + homS[i]
            ) ;
        }
    }
    rep(i, 1, r) {
        if (dp[i] >= k) {
            r -= i;
        }
    }
    sort(probT + 1, probT + n + 1);
    int sum = 0;
    rep(i, 1, n) {
        sum += probT[i];
        if (sum > r) {
            cout << i - 1;
            return 0;
        }
    }
    cout << n;
	return 0;
}
