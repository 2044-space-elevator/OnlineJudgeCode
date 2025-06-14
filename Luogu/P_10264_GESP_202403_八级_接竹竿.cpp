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

#define int unsigned
const int N = 1e4 + 5e3 + 5;


void solve() {
    int lstx[N] = {0}, jump[N] = {0}; 
    int n;
    cin >> n;
    rep(i, 1, n) {
        int x;
        cin >> x;
        jump[lstx[x]] = i;
        lstx[x] = i;;
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        int ans = 0;
        cin >> x >> y;
        rep(i, x, y) {
            if (x <= jump[i] && jump[i] <= y) i = jump[i];
            else ans++;
        }
        cout << ans << '\n';
    }
}

main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while (t--) solve();
	return 0;
}
