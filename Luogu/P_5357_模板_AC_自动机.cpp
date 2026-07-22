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

const int N = 1E6 + 5;
int n, ans[N], tr[N][26], ed[N], cnt, fail[N], ine[N], idx[N];
stg s[N];
stg t;

void insert(int ind) {
	int p = 0;
	for (char vt : s[ind]) {
		int v = vt - 'a';
		if (!tr[p][v]) tr[p][v] = ++cnt;
		p = tr[p][v];
	}
	if (!ed[p]) ed[p] = ++cnt;
	idx[ind] = ed[p];
}

void gfail() {
	queue<int> q;
	repq(i, 0, 26) {
		if (tr[0][i]) q.push(tr[0][i]);
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		repq(i, 0, 26) {
			if (tr[u][i]) {
				fail[tr[u][i]] = tr[fail[u]][i];
				ine[tr[fail[u]][i]]++;
				q.push(tr[u][i]);
			} else {
				tr[u][i] = tr[fail[u]][i];
			}
		}
	}
}

void topo() {
	queue<int> q;
	rep(i, 0, cnt) {
		if (!ine[i]) q.push(i);
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		ans[ed[u]] = ans[u];
		int v = fail[u];
		ans[v] += ans[u];
		if (!--ine[v]) q.push(v);
	}
}

void query() {
	int p = 0;
	for (char vt : t) {
		int v = vt - 'a';
		p = tr[p][v];
		ans[p]++;
	}
}

main() {
	cin >> n;
	rep(i, 1, n) { cin >> s[i]; insert(i); }
	cin >> t;
	gfail();
	query();
	topo();
	rep(i, 1, n) {
		cout << ans[idx[i]] << '\n';
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
