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

vct<int> arr;

main() {
//	int t; cin >> t; while (t--) solve();
    int m, q;
    cin >> m >> q;
    rep(i, 1, m) {
        int x;
        cin >> x;
        arr.insert(upper_bound(arr.begin(), arr.end(), x), x);
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 2) {
            int x;
            cin >> x;
            arr.insert(upper_bound(arr.begin(), arr.end(), x), x);
        } else {
            int x;
            cin >> x;
            cout << arr.at(arr.size() - x) << endl;
        }
    }
	return 0;
}
