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

const int N = 10505;
int fail[N];
int cnt;
int tr[N][27];
pair<int, int> fa[N];
int exist[N];
stg s[155], t;
int n;

void insert(int ind) {
	int p = 0;
	repq(i, 0, s[ind].size()) {
		int c = s[ind][i] - 'a';
		if (!tr[p][c]) tr[p][c] = ++cnt;
		fa[tr[p][c]] = {p, c};
		p = tr[p][c];
	}
	exist[p] = ind;
}

void make_fail() {
	queue<int> q;
	q.push(0);
	while (q.size()) {
		int u = q.front(); q.pop();
		repq(i, 0, 26) {
			if (tr[u][i]) {
				q.push(tr[u][i]);
				if (u == 0) continue;
				fail[tr[u][i]] = tr[fail[u]][i];
			} else tr[u][i] = tr[fail[u]][i];
		}
	}
}

int ans[155];


void solve() {
	if (!n) return ;
	cnt = 0;
	// cin >> n;
	memset(fail, 0, sizeof fail);
	memset(tr, 0, sizeof tr);
	memset(exist, 0, sizeof exist);
	memset(ans, 0, sizeof ans);
	rep(i, 1, n) {
		cin >> s[i];
		insert(i);
	}	
	cin >> t;
	// cout << cnt << '\n';e
	make_fail();
	int now = 0;
	repq(i, 0, t.size()) {
		now = tr[now][t[i] - 'a'];
		for (int t = now; t; t = fail[t]) {
			ans[exist[t]]++;
		}
	}
	int maxe = 0;
	rep(i ,1, n) {
		maxe = max(maxe, ans[i]);
	}
	cout << maxe << '\n';
	rep(i, 1, n) {
		if (ans[i] == maxe) {
			cout << s[i] << '\n';
		}
	}
}



main() {
	while (cin >> n) solve();
	return 0;
}
