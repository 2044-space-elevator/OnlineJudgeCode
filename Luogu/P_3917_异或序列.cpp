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

const int N = 1E5 +5;
bool w[N][32];
#define int ll

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    rep(i, 1, n) {
        int x;
        cin >> x;
        rep(j, 0, 31) {
            if (x & (1 << j)) {
                w[i][j] = 1;
            }
        } 
    }
    rep(i, 1, n) {
        rep(j, 0, 31) {
            w[i][j] ^= w[i - 1][j];
        }
    }
    ll ans = 0;
    rep(j, 0, 31) {
        ll b0 = 0, b1 = 0;
        rep(i, 0, n) {
            if (w[i][j]) b1++;
            else        b0++;
        }
        ans = ans + b1 * b0 * (1 << j);
    }
    cout << ans;
	return 0;
}
