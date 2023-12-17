#include <iostream>
#include <algorithm>
#include <cstring>
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

struct tmp {
    int P, Q, V;
}prices[5005];

int n, m, dp[5005];

void solve() {
    memset(dp, 0, sizeof(dp));
    rep(i, 1, n) {
        cin >> prices[i].P >> prices[i].Q >> prices[i].V;
    }
    sort(prices + 1, prices + n + 1, 
    [](tmp a, tmp b) {return a.Q - a.P < b.Q - b.P; });
    rep(i, 1, n) {
        rrep(j, max(prices[i].Q, prices[i].P), m) {
            dp[j] = max(dp[j - prices[i].P] + prices[i].V, dp[j]);
        }
    }
    cout << dp[m] << endl;
}

int main() {
    while (cin >> n >> m) {
        solve();
    }
    return 0;
}
