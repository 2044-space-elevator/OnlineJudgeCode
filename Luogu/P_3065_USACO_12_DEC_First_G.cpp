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

const int N = 3E4 + 5;
int tr[N * 10][26]; bool ed[N * 10];
int cnt, n;
stg s[N];
void insert(int ind) {
	int p = 0;
	for (char vt : s[ind]) {
		char v = vt - 'a';
		if (!tr[p][v]) tr[p][v] = ++cnt;
		p = tr[p][v];
	}
	ed[p] = 1;
}

bool ans[N];
bool E[26][26];
int ine[26];

void topo() {
	queue<int> q;
	rep(i, 0, 25) {
		if (!ine[i]) q.push(i);
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		repq(i, 0, 26) {
			if (!E[u][i]) continue;
			if (!--ine[i]) {
				q.push(i);
			}
		}
	}	
}

bool find(int ind) {
	memset(E, 0, sizeof E);
	memset(ine, 0, sizeof ine);
	int p = 0;
	for (char vt : s[ind]) {
		if (ed[p]) return 0;
		char v = vt - 'a';
		repq(kk, 0, 26) {
			if (kk == v) continue;
			if (!tr[p][kk]) continue;
			if (E[v][kk]) continue;
			E[v][kk] = 1;
			ine[kk]++;
		}
		p = tr[p][v];
	}
	topo();
	rep(i, 0, 25) {
		if (ine[i]) return 0;
	}
	return 1;
}



main() {
	cin >> n;
	rep(i, 1, n) {
		cin >> s[i];
		insert(i);
	}
	rep(i, 1, n) ans[i] = find(i);
	int res = 0;
	rep(i, 1, n) res += ans[i];
	cout << res << '\n';
	rep(i, 1, n) {
		if (ans[i]) cout << s[i] << '\n';
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
