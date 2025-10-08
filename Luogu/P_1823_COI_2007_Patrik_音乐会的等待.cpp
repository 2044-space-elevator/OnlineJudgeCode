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

struct person {
    int h, w; 
};

main() {
//	int t; cin >> t; while (t--) solve();
    ll ans = 0;
    int n;
    cin >> n;
    stack<person> st;
    rep(i, 1, n) {
        int x;
        cin >> x;
        person tmp = {x, 1};
        while (st.size() && st.top().h <= x) {
            ans += st.top().w;
            if (st.top().h == x) {
                tmp.w += st.top().w;
            }
            st.pop();
        }
        if (st.size()) ans++;
        st.push(tmp);
    }
    cout << ans;
	return 0;
}
