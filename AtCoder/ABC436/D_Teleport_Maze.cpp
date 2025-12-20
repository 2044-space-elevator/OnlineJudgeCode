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

int h, w;
bool vis[1005][1005], usede[200];
vector<pair<int, int> > zm[200];
char _m[1005][1005];

struct node {
	int x, y, step;
};
bool flg = 0;

void bfs() {
	queue<node> q;
	q.push({1, 1, 0});
	vis[1][1] = 1;
	while (q.size()) {
		if ((double)clock() / CLOCKS_PER_SEC >= 1.98) {
			cout << -1;
			flg = 1;
			return;
		}
		int x = q.front().x, y = q.front().y;
		// cout << x << ' ' << y << ' ' ;
		int step = q.front().step;
		q.pop();
		if (x == h && y == w) {
			cout << step;
			flg = 1;
			return;
		}
		int dxy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		repq(i, 0, 4) {
			int dx = dxy[i][0] + x, dy = dxy[i][1] + y;
			if (dx > h || dy > w || dx < 1 || dy < 1 || vis[dx][dy] || _m[dx][dy] == '#') continue;
			q.push({dx, dy, step + 1});
			vis[dx][dy] = 1;
		}
		if (usede[_m[x][y]]) continue;
		else usede[_m[x][y]] = 1;
		for (auto tmp : zm[_m[x][y]]) {
			int dx = tmp.first, dy = tmp.second;
			if (!vis[dx][dy]) {
				vis[dx][dy] = 1;
				q.push({dx, dy, step + 1});
			}
		}
	}

}

main() {
//	int t; cin >> t; while (t--) solve();
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	cin >> h >> w;
	rep(i, 1, h) {
		rep(j, 1, w) {
			cin >> _m[i][j];
			if ('a' <= _m[i][j] && _m[i][j] <= 'z')
				zm[_m[i][j]].push_back({i, j});
		}
	}
	bfs();
	if (!flg) cout << -1;
	return 0;
}
