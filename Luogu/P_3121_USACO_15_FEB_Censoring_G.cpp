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

stg t;
int n;
const int N = 1E5 + 5;
int ed[N], tr[N][26], fail[N], st[N], ans[N], cnt;
stg s[N];

void insert(int ind) {
	int p = 0;
	for (char vt : s[ind]) {
		int v = vt - 'a';
		if (!tr[p][v]) tr[p][v] = ++cnt;
		p = tr[p][v];
	}
	ed[p] = s[ind].size();
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

int loc[N];

main() {
	cin >> t >> n;
	rep(i, 1, n) {
		cin >> s[i];
		insert(i);
	}
	gfail();
	int p = 0, top = 0;
	repq(i, 0, t.size()) {
		loc[i] = p = tr[p][t[i] - 'a'];
		ans[++top] = i;
		if (ed[p]) {
			top -= ed[p];
			p = loc[ans[top]];
		}
	}
	rep(i, 1, top) {
		cout << t[ans[i]];
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
