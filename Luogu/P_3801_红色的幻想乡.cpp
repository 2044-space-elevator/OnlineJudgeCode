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
const int N = 1e5 + 5;
int cx[N], cy[N], n, m, ax[N], ay[N];
int lowbit(int x) {
    return x & (-x);
}
void add(int *c, int x, int val) {
    while (x <= *c) {
        *(c + x) += val;
        x += lowbit(x);
    } 
}

int query(int *c, int x) {
    int ans = 0;
    while (x >= 1) {
        ans += *(c + x);
        x -= lowbit(x);
    }
    return ans;
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n, m, q;
    cin >> n >> m >> q;
    cx[0] = n, cy[0] = m;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int xop, yop;
            cin >> xop >> yop;
            ax[xop] = ax[xop] ? 0 : 1;
            add(cx, xop, ax[xop] ? 1 : -1);
            ay[yop] = ay[yop] ? 0 : 1;
            add(cy, yop, ay[yop] ? 1 : -1);
        } else {
            int fx, fy, tx, ty;
            cin >> fx >> fy >> tx >> ty;
            int sx = query(cx, tx) - query(cx, fx - 1), 
            sy = query(cy, ty) - query(cy, fy - 1);
            int ans = (tx - fx + 1) * sy + (ty - fy + 1) * sx - sx * sy * 2;
            cout << ans << endl;
        }
    }
	return 0;
}
