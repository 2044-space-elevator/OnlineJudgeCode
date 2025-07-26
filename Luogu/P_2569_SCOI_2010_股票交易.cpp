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

int dp[2001][2001], n, m, w;

main() {
//	int t; cin >> t; while (t--) solve();
    memset(dp, 128, sizeof dp);
    cin >> n >> m >> w;
    rep(i, 1, n) {
        int ap, bp, as, bs;
        cin >> ap >> bp >> as >> bs;
        rep(j, 0, as) {
            dp[i][j] = -j * ap;
        }
        rep(j, 0, m) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        } 
        if (i <= w) {
            continue;
        }
        deque<int> q;
        rep(j, 0, m) {
            while (q.size() && q.front() < j - as) {
                q.pop_front();
            }
            while (q.size() && dp[i - w - 1][q.back()] + q.back() * ap <= dp[i - w - 1][j] + j * ap) {
                q.pop_back();
            }
            q.push_back(j);
            if (q.size()) {
                dp[i][j] = max((int)(dp[i - w - 1][q.front()] + q.front() * ap - j * ap), dp[i][j]);
            }
        }
        q.clear();
        rrep(j, 0, m) {
            while (q.size() && q.front() > j + bs) {
                q.pop_front();
            }
            while (q.size() && dp[i - w - 1][q.back()] + bp * q.back() <= dp[i - w - 1][j] + j * bp) {
                q.pop_back();
            }
            q.push_back(j);
            if (q.size()) {
                dp[i][j] = max(dp[i - w - 1][q.front()] + q.front() * bp - j * bp, dp[i][j]);
            }
        }
    }
    int ans = 0;
    rep(i, 0, m) {
        ans = max(dp[n][i], ans);
    }
    cout << ans;
	return 0;
}
