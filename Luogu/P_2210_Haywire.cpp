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

int n, per[13], ans = 114514;
bool G[13][13];


int get() {
    int res = 0;
    rep(i, 1, n) {
        rep(j, i + 1, n) {
            if (G[i][j]) {
                res += abs(per[i] - per[j]);
            }
        }
    }
    return res;

}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    rep(i, 1, n) {
        per[i] = i;
        rep(k, 1, 3) {
            int tmp;
            cin >> tmp;
            G[i][tmp] = G[tmp][i] = 1;
        }
    }
    do {
        ans = min(ans, get());
    } while (next_permutation(per + 1, per + n + 1));
    cout << ans;
	return 0;
}
