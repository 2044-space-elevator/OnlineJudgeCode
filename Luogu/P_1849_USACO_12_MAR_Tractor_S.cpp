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

int n, x00, y00;
int w, h;
bool _mp[1005][1005], vis[1005][1005];
bool bfs() {
	queue<pair<int, int> > q;
	q.push({x00, y00});
	vis[x00][y00] = 1;
	while (q.size()) {
		auto tmp = q.front();
		int x = tmp.first, y = tmp.second;
		q.pop();
		int dxy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		if (!x && !y) return true;
		repq(i, 0, 4) {
			int dx = dxy[i][0] + x, dy = dxy[i][1] + y;
			if (dx < 0 || dy < 0 || dx > w || dy > h || vis[dx][dy] ) continue;
			if (_mp[dx][dy]) {
				vis[dx][dy] = 1;
				_mp[dx][dy] = 0;
				continue;
			}
			q.push({dx, dy});
			vis[dx][dy] = 1;
		}
	}
	return false;
}

main() {
	cin >> n >> x00 >> y00;
	rep(i, 1, n) {
		int xt, yt; cin >> xt >> yt;
		_mp[xt][yt] = 1;
		w = max(w, xt);
		h = max(h, yt);
	}
	w = max(w, x00);
	h = max(h, y00);
	w += 2, h += 2;
	int i = 0;
	while (1) {
		memset(vis, 0, sizeof vis);
		if (bfs()) {
			cout << i;
			return 0;
		}
		i++;
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
