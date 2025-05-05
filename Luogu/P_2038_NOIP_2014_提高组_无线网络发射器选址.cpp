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

#define int ll
int ggcs[130][130];
main() {
//	int t; cin >> t; while (t--) solve();
    int d, n;
    cin >> d >> n;
    rep(i, 1, n ){
        int x, y, k;
        cin >> x >> y >> k;
        ggcs[x][y] = k;
    }
    int ans = 0;
    int fst = 0;
    rep(i, 0, 128) {
        rep(j, 0, 128) {
            int cnt = 0;
            rep(k, max(0ll, i - d), min(128ll, i + d)) {
                rep(l, max(0ll, j - d), min(128ll, j + d)) {
                    cnt += ggcs[k][l];
                }
            }
            if (ans < cnt) {
                fst = 1;
                ans = cnt;
            }
            else if (ans == cnt) fst++;
        }
    }
    cout << fst << ' ' << ans;
	return 0;
}
