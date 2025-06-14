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

const int N = 2e5;
vct<pair<int, int> > E[N];
int pl[N], pr[N], hei[N];
ll dis[N];
bool tof[N], tos[N], vis[N];
#define lc(a) a
#define rc(a) (a+n)

int n, s, t;

struct node {
	ll u, dis;
	bool operator > (const node &b) const {
		return dis > b.dis;
	}
};
priority_queue<node, vector<node>, greater<node> > q;

void dijkstra() {
	q.push({s, 0}); 
	memset(dis, 127, sizeof dis);
	dis[s] = 0;
	while (q.size()) {
		int u = q.top().u;
		ll d = q.top().dis;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto tmp : E[u]) {
			ll v = tmp.first, w = tmp.second;
			if (dis[v] > w + d) {
				dis[v] = w + d;
				q.push({v, dis[v]});
			}
		}
	}
}
bool cmp(pair<int, int> a, pair<int, int> b) {
	int fss = a.first, scc = b.first;
	if (fss > n) fss -= n;
	if (scc > n) scc -= n;
	// assert (fss > 0);
	// assert (scc > 0);
	// assert (scc < n);
	// assert (fss < n);
	// return 0;
	return hei[fss] > hei[scc];
}
main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> s >> t;
	rep(i, 1, n) {
		cin >> pl[i] >> pr[i] >> hei[i];
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			if (i == j) {
				continue;
			}
			if (pl[j] <= pl[i] && pl[i] <= pr[j] && hei[i] > hei[j]) {
				if (j != t) {
					E[i].push_back({j, hei[i] - hei[j] + pl[i] - pl[j]});
					E[i].push_back({rc(j), hei[i] - hei[j] + pr[j] - pl[i]});
				} else {
					tof[i] = 1;
					E[i].push_back({j, hei[i] - hei[j]});
					E[i].push_back({rc(j), hei[i] - hei[j]});
				}
				//cout << "!. " << i << ' ' << j << endl;
			}
			if (pl[j] <= pr[i] && pr[i] <= pr[j] && hei[i] > hei[j]) {
				if (j != t) {
					E[rc(i)].push_back({j, hei[i] - hei[j] + pr[i] - pl[j]});
					E[rc(i)].push_back({rc(j), hei[i] - hei[j] + pr[j] - pr[i]});
				} else {
					tof[i] = 1;
					E[rc(i)].push_back({j, hei[i] - hei[j]});
					E[rc(i)].push_back({rc(j), hei[i] - hei[j]});
				}
				//cout << "?. " << i << ' ' << j << endl;
			}
		}
	}
	//rep(i, 1, 2 * n) for (auto f  : E[i]) cout << i << ' ' << f.first << ' ' << f.second << endl;
	rep(i, 1, 2 * n) {
	 	if (E[i].size()) {
	 		sort(E[i].begin(), E[i].end(), cmp);
	 		pair<int, int> ff = E[i][0];
			pair<int, int> ss = {0, 0};
	 		if (E[i].size() > 1) ss= E[i][1];
	 		E[i].clear();
	 		E[i].push_back(ff);
	 		if (hei[ff.first - (ff.first > n) * n] == hei[ss.first - (ss.first > n) * n]) E[i].push_back(ss);
	 	}
	 	if (i <= n) {
	 		E[i].push_back({rc(i), pr[i] - pl[i]});
	 	} else E[i].push_back({i - n, pr[i - n] - pl[i - n]});
	 }
	dijkstra();
	//cout << dis[114];
	if (dis[t] >= dis[2001] && dis[rc(t)] >= dis[2001])  {
		cout << "-1";
	} else
		cout << min(dis[rc(t)], dis[t]);
	return 0;
}
