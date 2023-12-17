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


main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    int maxx = -1e6, maxxy = -1e6;
    int maxy = -1e6, maxyx = -1e6;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x > maxx) {
            maxx = x;
            maxxy = y;
        }
        if (y > maxy) {
            maxy = y;
            maxyx = x;
        }
    }
    cout << abs(maxy - maxxy) + abs(maxyx - maxx);
	return 0;
}
