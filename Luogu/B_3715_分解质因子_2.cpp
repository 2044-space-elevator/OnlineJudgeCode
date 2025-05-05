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
    ll n;
    cin >> n;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << ' ' ;
            n /= i;
        }
    }
    if (n != 1) cout << n;
    cout << endl;
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
