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

int dp[5005];
int k;
const int mod = 998244353;


void solve() {
    char op;
    int num;
    cin >> op >> num;
    if (op == '+') {
        rrep(i, num, k) {
            dp[i] += dp[i - num];
            dp[i] %= mod;
        } 
    } else {
        rep(i, num, k) {
            dp[i] -= dp[i - num];
            dp[i] += mod;
            dp[i] %= mod;
        }
    }
    cout << dp[k] << endl;
}


main() {
    dp[0] = 1;
	int t; cin >> t >> k; while (t--) solve();
	return 0;
}
