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

const int N = 2e5 + 5;
int dp[N], arr[N], n, l, r;

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> l >> r;
    memset(dp, 128, sizeof dp);
    dp[0] = 0;
    rep(i, 0, n) cin >> arr[i];
    deque<int> q; q.clear();
    q.push_back(0);
    rep(i, l, n) {
        while (q.size() && !(q.front() + l <= i && i <= q.front() + r)) {
            q.pop_front();
        }
        dp[i] = dp[q.front()] + arr[i];
        while (q.size() && dp[q.back()] >= dp[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    int ans = 0;
    rep(i, n - r + 1, n) ans = max(ans, dp[i]);
    cout << ans;
	return 0;
}
