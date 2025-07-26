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

ll brow[505][505], s[505][505], n, m, A, B;
bool check(ll x) {
    int now = 0, amount = 0;
    rep(i, 1, n) {
        int choc = 0, sum = 0;
        rep(j, 1, m) {
            ll tmp = s[i][j] - s[i][j - 1] - (s[now][j] - s[now][j - 1]);
            if (choc + tmp < x) {
                choc += tmp;
            } else {
                sum++;
                choc = 0;
            }
        }
        if (sum >= B) {
            now = i, amount++;
        }
    }
    if (amount >= A) {
        return 1;
    }
    return 0;
}


main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m >> A >> B;
    rep(i, 1, n) {
        rep(j, 1, m) {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    ll l = 0, r = s[n][m], ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r;
	return 0;
}
