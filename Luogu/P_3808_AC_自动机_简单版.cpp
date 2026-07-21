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
const int N = 1E6 + 5;
stg s[N], t;
int tr[N][26], fail[N], cnt, exist[N];

void insert(int ind) {
	int p = 0;
	for (char vt : s[ind]) {
		int v = vt - 'a';
		if (!tr[p][v]) tr[p][v] = ++cnt;
		p = tr[p][v];
	}
	exist[p]++;
}

void gfail() {
	queue<int> q;
	repq(i, 0, 26) {
		if (tr[0][i])
			q.push(tr[0][i]);
	}
	while(q.size()) {
		int u = q.front(); q.pop();
		repq(i, 0, 26) {
			if (tr[u][i]) {
				fail[tr[u][i]] = tr[fail[u]][i];
				q.push(tr[u][i]);
			} else {
				tr[u][i] = tr[fail[u]][i];
			}
		}
	}
}

main() {
	cin >> n;
	rep(i, 1, n) {
		cin >> s[i];
		insert(i);
	}
	gfail();
	cin >> t;
	int p = 0, ans = 0;
	for (char v : t) {
		p = tr[p][v - 'a'];
		for (int t = p; t && exist[t] != -1; t = fail[t]) {
			ans += exist[t];
			exist[t] = -1;
		}
	}
	cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
