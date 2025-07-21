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
    string st;
    cin >> st;
    int cnt = 0;
    repq(i, 0, st.size()) {
        if (st[i] == '#') {
            cnt++;
            if (cnt % 2) {
                cout << i + 1;
            } else {
                cout << ',' << i + 1 << '\n';
            }
        }
    }
	return 0;
}
