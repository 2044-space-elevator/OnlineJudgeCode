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

const int mod = 1e8;
ll A[(int)3e5 + 5];
ll sum[(int)3e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    rep(i, 1, n) {
        cin >> A[i];
        sum[i] = sum[i - 1] + A[i];
        sum[i] %= mod;
    }
    ll ans = 0;
    repq(i, 1, n) {
        ans = ans + (n - i) * A[i] % mod;
        ans %= mod;
        ans = ans + (sum[n] - sum[i] + mod) % mod;
        ans %= mod;
    }
    cout << ans;
	return 0;
}
