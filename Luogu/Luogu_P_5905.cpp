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
#define int ll

void solve() {
	
}

const int INF = 1e9;
const int N = 1e4 + 5, M = 1e4 + 5;
int head[N], cnt, vis[N], hdis[N], tot[N], dis[N], n, m;
struct edge {
	int u, v, w, next;
}E[M];
struct node {
	int w, now;
	bool operator < (const node& x) const {
		return w > x.w;
	}
};
priority_queue<node> q;
void add(int u, int v, int w) {
	E[++cnt] = {u, v, w, head[u]};
	head[u] = cnt;
}

bool spfa() {
	int s = 0;
	memset(hdis, 63, sizeof(hdis));
	hdis[s] = 0, vis[s] = 1;
	queue<int> q;
	q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = E[i].next) {
			int v = E[i].v;
			if (hdis[v] > hdis[u] + E[i].w) {
				hdis[v] = hdis[u] + E[i].w;
				if (!vis[v]) {
					vis[v] = 1;
					q.push(v);
					tot[v]++;
					if (tot[v] == n + 1) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

void input() {
	cin >> n >> m;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
}

void add_edge() {
	rep(i, 1, n) {
		add(0, i, 0);
	}
	if (!spfa()) {
		cout << "-1\n";
		exit(0);
	}
	rep(u, 1, n) {
		for (int i = head[u]; i; i = E[i].next) {
			E[i].w += hdis[u] - hdis[E[i].v];
		}
	}
}

void dijkstra(int s) {
	rep(i, 1, n) {
		dis[i] = INF;
	}	
	q.push({0, s});
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	while (q.size()) {
		node frt = q.top(); q.pop();
		int u = frt.now;
		if (vis[u]) {
			continue;
		}
		vis[u] = 1;
		for (int i = head[u]; i; i = E[i].next) {
			int v = E[i].v;
			if (dis[v] > dis[u] + E[i].w) {
				dis[v] = dis[u] + E[i].w;
				if (!vis[v]) {
					q.push({dis[v], v});
				}
			}
		}
	}
}
main() {
//	int t; cin >> t; while (t--) solve();
	input();
	add_edge();
	rep(i, 1, n) {
		dijkstra(i);
		int ans = 0;
		rep(j, 1, n) {
			if (dis[j] == INF) {
				ans += j * INF;
			} else {
				ans += j * (dis[j] + hdis[j] - hdis[i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
