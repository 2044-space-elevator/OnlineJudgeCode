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
map<int, bool> _m;

void solve() {
	_m.clear();
    int n;
    cin >> n;
    deque<int> q;
    int ans = 0, now = 1;
    rep(i, 1, n) {
        int x;
        cin >> x;
        while (_m[x]) {
            _m[q.front()] = 0;
            q.pop_front();
        }
        q.push_back(x);
        _m[x] = 1;
        ans = max(ans, (int)q.size());
    }
    cout << ans << endl;
}



main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
