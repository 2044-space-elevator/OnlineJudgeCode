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

int C[16], P[16], L[16];

void exgcd(int a, int b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0; return ;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    int st = 0;
    rep(i, 1, n ){
        cin >> C[i] >> P[i] >> L[i];
        st = max(st, C[i]);
    }
    rep(m, st, 1e6) {
        // m = 20 时崩溃
        rep(i, 1, n) {
            rep(j, i + 1, n) {
                int a = P[i] - P[j], b = m, c = C[j] - C[i];
                int d = gcd(a, b);
                //if (d == 0) { cout << "thatbeifen"; return 0; }
                if (c % d) continue;
                ll x, y;
                exgcd(a, b, x, y);
                a /= d, b /= d, c /= d;
                if (b < 0) b = -b;
                x = (x * c % b + b) % b;
                if (x <= L[i] && x <= L[j]) goto _;
            }
        }
        cout << m; return 0;
        _:;
    }
	return 0;
}
