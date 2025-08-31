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
#define float long double
const int N = 8E4 + 5;
int n, m, s, dfn[N], low[N], cnt, scc[N], in_st[N], scc_cnt;
stack<int> st;
struct edge {
    int v, mg;
    float prod;
};
struct edge_normal {
    int u; edge e;
};
vct<edge> E[N];
vct<edge_normal> E_;

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;    
    st.push(u);
    in_st[u] = 1;
    for (auto tmp : E[u]) {
        int v = tmp.v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_st[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        scc_cnt++;
        int j = -1;
        do {
            j = st.top();
            st.pop();
            scc[j] = scc_cnt;
            in_st[j] = 0;
        } while (j != u);
    }
}


struct edge_p {
    int v, w;
};
vct<edge_p> E_spfa[N];
int dis[N], sum[N];
bool vis[N];
queue<int> q;

void spfa() {
    memset(dis, -1, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[s] = sum[s];
    vis[s] = 1;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (auto ed : E_spfa[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] < dis[u] + w + sum[v]) {
                dis[v] = dis[u] + w + sum[v];
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v, mg; float prod;
        cin >> u >> v >> mg >> prod;
        edge tmp = {v, mg, prod};
        E[u].push_back(tmp);
        E_.push_back({u, tmp});
    }
    rep(i, 1, n) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    ll ans = 0;
    for (auto tmp : E_) {
        int fr = tmp.u, to = tmp.e.v, mg = tmp.e.mg;
        float prod = tmp.e.prod;
        if (scc[fr] == scc[to]) {
            while(mg) {
                sum[scc[fr]] += mg;
                mg = (int)(mg * prod);
            }
        } else {
            E_spfa[scc[fr]].push_back({scc[to], mg});
        }
    }
    cin >> s;
    s = scc[s];
    spfa();
    rep(i, 1, scc_cnt) {
        ans = max(ans, dis[i]) ;
    }
    cout << ans;
	return 0;
}