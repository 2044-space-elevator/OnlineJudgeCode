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
const int N = 2e5 + 5;
int n, m;
ll s, w[N], v[N], qzh[N], qzh2[N], l[N], r[N], an, res;

void prefix(ll x) {
    memset(qzh, 0, sizeof qzh);
    memset(qzh2, 0, sizeof qzh2);
    rep(i, 1, n) {
        qzh[i] = qzh[i - 1] + (w[i] >= x);
        qzh2[i] = qzh2[i - 1] + (w[i] >= x) * v[i];
    }
}

bool  check(ll x) {
    prefix(x);
    res = 0;
    rep(i, 1, m) {
        res += (qzh[r[i]] - qzh[l[i] - 1]) * (qzh2[r[i]] - qzh2[l[i] - 1]);
    }
    return res > s;
}


main() {
//	int t; cin >> t; while (t--) solve();
    an = 1e18;
    cin >> n >> m >> s;
    rep(i, 1, n) {
        cin >> w[i] >> v[i];
    }
    rep(i, 1, m) {
        cin >> l[i] >> r[i];
    }
    ll l = 1, r = *max_element(w + 1, w + n + 1) + 1;
    while (l <= r) {
        ll mid = l + (r - l) / 2ll;   
        if (check(mid)) {
            l = mid + 1;
            an = min(an, llabs(res - s));
        } else {
            r = mid - 1;
            an = min(an, llabs(res - s));
        }
    }
    cout << an; 
    
	return 0;
}
