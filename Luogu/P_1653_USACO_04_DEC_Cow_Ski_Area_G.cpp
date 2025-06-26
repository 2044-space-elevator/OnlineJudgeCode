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

const int N = 250005;
int grp[505][505], n, scccnt, cnt, W, L, dfn[N], low[N], belonged[N], inn[N], out[N], vis[505][505];
bool in[N];
stack<int> st;
vct<int> E[N];

inline int loc(int x,int y) { return  (x - 1) * L + y; }


void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    st.push(u); in[u] = 1;
    for (int v : E[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        int j = -1; ++scccnt;
        while (j != u) {
            j = st.top(); st.pop();
            belonged[j] = scccnt;
            in[j] = 0;
        }
    }
}

void pd(int i, int j, int x, int y) {
    if (x <= 0 || y <= 0 || x > W || y > L) return;
    if (grp[i][j] >= grp[x][y]) E[loc(i, j)].push_back(loc(x, y));
}


main() {
//	int t; cin >> t; while (t--) solve();
    cin >> W >> L;
    swap(W, L);
    n = W * L;
    rep(i, 1, W) {
        rep(j, 1, L) {
            cin >> grp[i][j];
        }
    }
    rep(i, 1, W) {
        rep(j, 1, L) {
            pd(i, j, i - 1, j);
            pd(i, j, i, j - 1);
            pd(i, j, i, j + 1);
            pd(i, j, i + 1, j);
        }
    }
    rep(i, 1, n) {
        if (!dfn[i]) tarjan(i);
    }
    rep(u, 1, n) {
        for (int v : E[u]) {
            if (belonged[u] == belonged[v]) continue;
            inn[belonged[v]]++, out[belonged[u]]++;
        }
    }
    if (scccnt == 1) {
        cout << 0;
        return 0;
    }
    int ans1 = 0, ans2 = 0;
    rep(i, 1, scccnt) {
        ans1 += !inn[i], ans2 += !out[i];
    }
    cout << max(ans1, ans2);
	return 0;
}
