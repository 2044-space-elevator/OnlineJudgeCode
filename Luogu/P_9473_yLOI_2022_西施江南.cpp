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

int prime[13005], cnt;
bool isprim[13005], vis[13005];
set<int> s;

void solve() {
    int n;
    cin >> n;
    rep(i, 1, cnt) {
        vis[i] = 0;
    }
    s.clear();
    bool ans = 1;
    rep(i, 1, n) {
        int x;
        cin >> x;
        rep(j, 1, cnt) {
            if (x % prime[j] == 0) {
                if (vis[j]) {
                    ans = 0;
                }
                vis[j] = 1;
                while (x % prime[j] == 0) {
                    x /= prime[j];
                }
            }
        }
        if (x != 1) {
            if (s.find(x) == s.end()) {
                s.insert(x);
            } else ans = 0;
        }
    }
    if (n == 2 || ans) {
        rty
        return;
    }
    rtn
}



main() {
    memset(isprim, true, sizeof isprim);
    isprim[1] = 0;
    rep(i, 2, 13000) {
        if (isprim[i]) prime[++cnt] = i;
        for (int j = 1; i * prime[j] <= 13000 && j <= cnt; j++) {
            isprim[i * prime[j]] = 0;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
	int t; cin >> t; while (t--) solve();
	return 0;
}	

