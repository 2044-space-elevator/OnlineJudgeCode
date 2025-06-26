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

const int N = 1E5 + 5, M = 5E5 + 5;
int dfn[N], low[N], root, n, m, belonged[N], cnt, out[N], scccnt;
stack<int> st;
bool flg[N], in[N];
vct<int> E[N];

void tarjan(int u) {
	dfn[u] = low[u] = ++cnt;
	st.push(u); in[u]= 1;
	int child = 0;
	for (int v : E[u]) {
		if (!dfn[v]) {
			child++;
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (in[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++scccnt; 
		int j = -1;
		while (j != u) {
			j = st.top();
			in[j] = 0;
			belonged[j] = scccnt;
			st.pop();
		}
	}
}

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m;
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		if (u == v) continue;
		E[u].push_back(v);
	}
	rep(i, 1, n) if (!dfn[i]) tarjan(i);
	rep(u, 1, n) {
		for (int v : E[u]) {
			if (belonged[v] == belonged[u]) continue;
			out[belonged[v]]++;
		}
	}
	int ans = 0;
	rep(i, 1, scccnt) {
		if (!out[i]) ans++;
	}
	cout << (ans == 0 ? 1 : ans);
	return 0;

}
