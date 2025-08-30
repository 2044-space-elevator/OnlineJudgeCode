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

int n, m, arr[25];
bool dp[2005];
main() {
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> arr[i];
    }
    int res = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) != n - m) continue;
        vct<int> per; per.clear();
        rep(j, 1, n) {
            if ((i >> (j - 1)) & 1) {
                per.push_back(arr[j]);
            }
        }
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        int sum = 0, cnt = 0;
        for (int v : per) {
            rrep(j, 0, sum) {
                if (!dp[j + v] && dp[j]) {
                    dp[j + v] = 1, cnt++;
                } 
            }
            sum += v;
        }
        res = max(res, cnt);
    }
    cout << res;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
