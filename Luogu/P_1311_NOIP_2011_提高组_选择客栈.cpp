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

int n, k, p;
vct<int> colors[51];
int col[(int)2e5 + 5];
int ffmin[(int)2e5 + 5][32]; 

int rmin(int l, int r) {
    int k = log2(r - l + 1);
    return min(ffmin[l][k], ffmin[r - (1 << k) + 1][k]);
}

main() {
    cin >> n >> k >> p;
    rep(i, 1, n) {
        int color, d;
        cin >> color >> d;
        col[i] = color;
        ffmin[i][0] = d;
        colors[color].push_back(i);
    }
    for (int j = 1; 1 << j <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            ffmin[i][j] = min(ffmin[i][j - 1], ffmin[i + (1 << j - 1)][j - 1]);
        }
    }
    ll ans = 0;
    rep(i, 1, n) {
        auto st = lower_bound(colors[col[i]].begin(), colors[col[i]].end(), i);
        auto tmp = st;
        while (st != colors[col[i]].end()) {
            if (rmin(i, *st) <= p) {
                break;
            }
            st++;
        }
        if (st == tmp) st++; 
        ans += (colors[col[i]].end() - st);
    }
    cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
