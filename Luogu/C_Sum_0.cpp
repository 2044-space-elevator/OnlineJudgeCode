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
int n;
struct node {
    int l, r;
}nd[(int)2e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    int les = 0, las = 0;
    rep(i, 1, n) {
        cin >> nd[i].l >> nd[i].r;
        les += nd[i].l;
        las += nd[i].r;
    }
    if (les <= 0 && las >= 0) cout << "Yes\n"; else {
        cout << "No";
        return 0;
    }
    int diff = -les;
    rep(i, 1, n) {
        int tmp = min(diff, nd[i].r - nd[i].l);
        nd[i].l += tmp;
        diff -= tmp;
        cout << nd[i].l << ' ';
    }
    cout << endl;
	return 0;
}
