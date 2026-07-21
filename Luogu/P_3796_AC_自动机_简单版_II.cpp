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

stg s[155];
stg t;
int n, tr[10505][26], exist[10505], fail[10505];
int cnt;

void insert(int ind) {
	int p = 0;
	for (char vt : s[ind]) {
		char v = vt - 'a';
		if (!tr[p][v]) tr[p][v] = ++cnt;
		p = tr[p][v];
	}
	exist[p] = ind;
}

void gfail() {
	queue<int> q;
	repq(i, 0, 26) {
		if (tr[0][i])
			q.push(tr[0][i]);
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		repq(i, 0, 26) {
			if (tr[u][i]) {
				fail[tr[u][i]] = tr[fail[u]][i];
				q.push(tr[u][i]);
			} else tr[u][i] = tr[fail[u]][i];
		}
	}
	
}
int ans[155];

void solve() {
	if (!n) return;
	cnt = 0;
	memset(ans, 0, sizeof ans);
	memset(tr, 0, sizeof tr);
	memset(exist, 0, sizeof exist);
	memset(fail, 0, sizeof fail);
	rep(i, 1, n) {
		cin >> s[i];
		insert(i);
	}
	gfail();
	cin >> t;
	int maxe = 0;
	int p = 0;
	for (char v : t) {
		p = tr[p][v - 'a'];
		for (int t = p; t; t = fail[t]) {
			ans[exist[t]]++;
		}
	}
	rep(i, 1, n) {
		maxe = max(maxe, ans[i]);
	}	
	cout << maxe << '\n';
	rep(i, 1, n) {
		if (maxe == ans[i]) {
			cout << s[i] << '\n';
		}
	}
}


main() {
	while (cin >> n) solve();
//	int t; cin >> t; while (t--) solve();
	return 0;
}
