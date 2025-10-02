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

const int N = 3E6 + 5;
int init[N][20], arr[N], cf[N];

main() {
//	int t; cin >> t; while (t--) solve();
    rep(i, 1, 2.5e6) {
        init[i][0] = i + log2(i);
    }
    rep(j, 1, 18) {
        rep(i, 1, 2.5e6) {
            init[i][j] = init[init[i][j - 1]][j - 1];
        }
    }
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> arr[i];
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        cf[l]++, cf[r + 1]--;
    }
    rep(i, 1 ,n) {
        cf[i] += cf[i - 1];
    }
    rep(i, 1, n) {
        int optimes = cf[i], v = arr[i];
        rrep(i, 0, 18) {
            if (optimes >= (1 << i)) {
                v = init[v][i];
                optimes -= (1 << i); 
            }
        }
        cout << v << ' ';
    }
	return 0;
}
