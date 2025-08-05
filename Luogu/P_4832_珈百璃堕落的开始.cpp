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

int delt = 2e6;
const int N = 5e6;
ll dp[2][N], s[N], c[N], w[N];

main() {
//	int t; cin >> t; while (t--) solve();
memset(dp, 128, sizeof dp);
    int n;
    cin >> n;
    ll minf = 0, maxf = 0;
    rep(i ,1, n) {
        stg st;
        cin >> st;
        for (char v : st) {
            if (v == 's') s[i]++;
            if (v == 'c') c[i]++;
        }
        w[i] = s[i] - c[i];
    }
    dp[0][delt] = 0;
    rep(i, 1, n) {
        minf = min(minf, minf + w[i]);
        maxf = max(maxf, maxf + w[i]);
        rep(j, minf, maxf)
            dp[i % 2][j + delt] = max(dp[!(i % 2)][j + delt], dp[!(i % 2)][j + delt - w[i]] + c[i]);
    }
    cout << dp[n % 2][delt];
	return 0;
}
