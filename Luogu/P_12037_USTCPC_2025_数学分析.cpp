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

long long n;
double arr[(int)1e5 + 5], f[(int)1e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    f[0] = atan(1);
    f[1] = log(2) / 2.0;
    rep(i, 0, n) cin >> arr[i];
    rep(i, 2, n) {
        f[i] = 1 / (i - 1) - f[i - 2];
    }
    double ans = 0;
    rep(i, 0, n) {
        ans += arr[i] * f[i];
    }
    printf("%.10lf", ans);
	return 0;
}

