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

const int N = 1e6 + 5;
int fail[N];
int cnt;
int tr[N][27];
pair<int, int> fa[N];
int exist[N];
stg s[N], t;
int n;

void insert(int ind) {
	int p = 0;
	repq(i, 0, s[ind].size()) {
		int c = s[ind][i] - 'a';
		if (!tr[p][c]) tr[p][c] = ++cnt;
		fa[tr[p][c]] = {p, c};
		p = tr[p][c];
	}
	exist[p]++;
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

int ans[N];


void solve() {
	cin >> n;
	cnt = 0;
	// cin >> n;
	rep(i, 1, n) {
		cin >> s[i];
		insert(i);
	}	
	cin >> t;
	// cout << cnt << '\n';e
	make_fail();
	int now = 0;
	int ans = 0;
	repq(i, 0, t.size()) {
		now = tr[now][t[i] - 'a'];
		for (int tt = now; tt && exist[tt] != -1; tt = fail[tt]) {
			ans += exist[tt];
			exist[tt] = -1;
		}
	}
	cout << ans << '\n';

}



main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
