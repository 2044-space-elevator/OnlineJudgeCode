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


const int INF = 1e9;
const int N = 1e4 + 5, M = 1e4 + 5;
int head[N], cnt, vis[N], hdis[N], tot[N], dis[N], n, m, k, cases = 0;
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
  m = 0;
	while (1) {
		int u, v, w;
		cin >> u >> v;
		if (u == 0 && v == 0) {
      return;
    }
    m++;
    add(u, v, -1);

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
	rep(i, 1, m) {
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

void solve() {
  memset(head, 0, sizeof(head));
  memset(vis, 0, sizeof vis);
  memset(dis, 0, sizeof dis);
  memset(hdis, 0, sizeof hdis);
  memset(tot, 0, sizeof tot);
  cnt = 0;
  input();
	add_edge();
  dijkstra(k);
  int res = INT_MIN, indi;
  rep(i, 1, n) {
    int tmp = dis[i] + hdis[i] - hdis[k];
		tmp = -tmp;
    if (res < tmp) {
      indi = i;
      res = tmp;
    }
  }
	printf("Case %lld: The longest path from %lld has length %lld, finishing at %lld.\n\n", cases, k, res, indi);
}
main() {
//	int t; cin >> t; while (t--) solve();
  while (cin >> n >> k) {
		cases++;
    solve();
  }
	return 0;
}

