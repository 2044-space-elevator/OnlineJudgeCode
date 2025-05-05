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

int n, mod;
ll inv[(int)3e6 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> mod;
    inv[1] = 1;
    cout << 1 << endl;
    rep(i, 2, n) {
        inv[i] = (mod -mod / i) * inv[mod % i] % mod;
        cout << inv[i] << endl;
    }
	return 0;
}
