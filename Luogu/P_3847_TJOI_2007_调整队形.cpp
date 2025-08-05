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

int dp[3005][3005], arr[3005];

main() {
//	int t; cin >> t; while (t--) solve();
int n;
    cin >> n;
    rep(i, 1, n) cin >> arr[i];
    memset(dp, 127, sizeof dp);
    rep(i, 1, n) {
        dp[i][i] = 0;
        if (i < n) {
            dp[i][i + 1] = (arr[i] != arr[i + 1]);
        }
    }
    rep(len, 3, n) {
        rep(i, 1, n - len + 1) {
            int j = i + len - 1;
            if (arr[i] == arr[j]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]}) + 1;
        }
    }
    cout << dp[1][n];
	return 0;

}
