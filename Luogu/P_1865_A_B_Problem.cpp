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

const int N = 1e6;
vct<int> pri;
bool prim[N + 5];
int pri_sum[N + 5];

main() {
//i	int t; cin >> t; while (t--) solve();
memset(prim, 1, sizeof prim);
    repq(i, 2, N) {
        if (prim[i]) {
            pri.push_back(i);
        }
        for (int j : pri) {
            if (i * j > N) break;
            prim[i * j] = 0;
            if (i % j == 0) break;
        }
    }
    repq(i, 2, N) {
        pri_sum[i] = pri_sum[i - 1] + prim[i];
    }
    int q, m;
    cin >> q >> m;
    rep(i, 1, q) {
        int l, r;
        cin >> l >> r;
        if (l < 1 || l > m || r < 1 || r > m) {
            cout << "Crossing the line\n";
            continue;
        }
        cout << pri_sum[r] - pri_sum[l - 1] << '\n';
    }
	return 0;
}
