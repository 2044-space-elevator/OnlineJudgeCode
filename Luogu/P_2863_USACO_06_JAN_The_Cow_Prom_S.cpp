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

const int N = 1e4 + 5;
int dfn[N], low[N], cnt, scccnt, sccco[N], n, m;
vct<int> E[N];
bool in[N];
stack<int> st;

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    st.push(u); in[u] = 1;
    for (int v : E[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        int j = -1; scccnt++;
        while (j != u) {
           j = st.top(); st.pop(); in[j] = 0;
           sccco[scccnt]++; 
        }   
    }
}


main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
    }
    rep(i, 1, n) {
        if (!dfn[i]) tarjan(i);
    }
    int ans = 0;
    rep(i, 1, scccnt) ans += sccco[i] > 1;
    cout << ans;
	return 0;
}
