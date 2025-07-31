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

int n;
const int N = 1E4 + 5;
int ste[N], len[N], in[N];
bool vis[N];
vct<int> E[N];
struct task {
    int u, step;
};

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    rep(i, 1, n) {
        cin >> len[i] >> len[i];
        int pref;
        while (cin >> pref) {
            if (!pref) break;
            E[pref].push_back(i);
            in[i]++;
        }
    }
    queue<int> q;
    rep(i, 1, n) {
        if (!in[i]) {
            q.push(i);
            ste[i] = len[i];
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for (int v : E[u]) {
            if (!--in[v]) {
                q.push(v);
            }
            ste[v] = max(ste[v], ste[u] + len[v]);
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        ans = max(ans, ste[i]);
    } 
    cout << ans;
	return 0;
}
