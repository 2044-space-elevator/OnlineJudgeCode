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

bool vis[(int)5e5 + 5], f[(int)5e5 + 5];


void solve() {
    memset(vis, 0, sizeof vis);
    memset(f, 0, sizeof f);
    int n;
    cin >> n;
    stg s;
    cin >> s;
    for (int i = 1; i < (1 << n); i++) {
        if (s[i - 1] == '0') {
            vis[i] = 1;
        } 
    }
    f[0] = 1;
    for (int i = 0; i < (1 << n); i++) {
        if (!vis[i]) continue;
        repq(k, 0, n) {
            if (i & (1 << k)) {
                f[i] |= f[i ^ (1 << k)];
            }
        }
    }
    if (f[(1 << n) - 1]) rty
    else rtn
    // cout << c[4][3];
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
