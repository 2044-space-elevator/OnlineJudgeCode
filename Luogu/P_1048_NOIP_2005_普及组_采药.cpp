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

int weight[105], value[105], dp[1005];

main() {
//	int t; cin >> t; while (t--) solve();
    int n, m;
    cin >> n >> m;
    rep(i, 1, m) {
        cin >> weight[i] >> value[i];
    }
    rep(i, 1, m) {
        rrep(j, weight[i], n) {
            dp[j] = 
            max(
                dp[j],
                dp[j - weight[i]] + value[i]
            );
        }
    }
    cout << dp[n];
	return 0;
}
