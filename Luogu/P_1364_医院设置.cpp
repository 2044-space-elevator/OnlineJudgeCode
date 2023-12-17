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

vct<int> E[105];
int people[105];

struct Bfs {
    int node, dist; 
};

int dp[101][101];
int n;

void dynamic_programming() {
    // k->i->j
    // i->j->k
    // g[j][k]=g[j][i]+g[i][k];
    rep(i, 1, n) {
        rep(j, 1, n) {
            if (i == j) {
                continue;
            }
            rep(k, 1, n) {
                if (i == k || j == k) {
                    continue;
                }
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    } 
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    rep(i, 1, n) {
        rep(j, 1, n) {
            dp[i][j] = 1e9;
            if (i == j) {
                dp[i][j] = 0;
            }
        }
    }

    rep(i, 1, n) {
        int w, u, v;
        cin >> w >> u >> v;
        people[i] = w;
        if (u > 0) {
            dp[i][u] = dp[u][i] = 1;
        } if (v > 0) {
            dp[i][v] = dp[v][i] = 1;
        }
    } 
    dynamic_programming();
    int mine = INT_MAX;
    rep(i, 1, n) {
        int cnt = 0;
        rep(j, 1, n) {
            if (dp[i][j] <= 1e6)
                cnt += dp[i][j] * people[j];
        }
        mine = min(mine, cnt);
    }
    cout << mine;
	return 0;
}
