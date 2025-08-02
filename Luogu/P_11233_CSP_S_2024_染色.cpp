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
int n, arr[(int)2e5 + 5], lst[(int)1e6 + 5], sum[(int)2e5 + 5];
ll dp[(int)2e5 + 5];

void solve() {
    cin >> n;
    rep(i, 1, n) cin >> arr[i];
    dp[0] = sum[0] = 0;
    memset(lst, 0, sizeof lst);
    rep(i, 1, n) {
        sum[i] = sum[i - 1] + (arr[i] == arr[i - 1]) * arr[i];
        dp[i] = dp[i - 1];
        if (lst[arr[i]]) {
            dp[i] = max(dp[i], dp[lst[arr[i]] + 1] + arr[i] + sum[i - 1] - sum[lst[arr[i]]]);
        }
        lst[arr[i]] = i;
    }
    cout << dp[n] << endl;
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
