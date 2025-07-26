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

int n, s, t;
double ans = 0, arr[(int)1e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> s >> t;
    rep(i, 1, n) { cin >> arr[i]; arr[i] += arr[i - 1]; }
    rep(len, s, t) {
        rep(l, 1, n - len + 1) {
            int r = l + len - 1;
            ans = max(ans, (arr[r] - arr[l - 1]) / len);
        }
        if ((double)clock() / CLOCKS_PER_SEC >= 0.96) break;
    }
    printf("%.3lf", ans);
	return 0;
}
