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

vct<int> Edge[10005];
int n, dp[10005], cnt;

void dfs(int u, int father) {
    for (int v : Edge[u]) {
        if (v == father) {
            continue;
        }
        dp[v] = dp[u] + 1;
        if (dp[v] > dp[cnt]) {
            cnt = v;
        }
        dfs(v, u);
    }
}

int main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        Edge[x].push_back(y);
        Edge[y].push_back(x);
    }
    dfs(1, 0); dp[cnt] = 0; dfs(cnt, 0); cout << dp[cnt];
	return 0;
}
