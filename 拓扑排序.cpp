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
vct<int> g[105];
int innode[105];
vct<int> res;
void AovSort(int n) {
	queue<int> q;
	int k = 0;
	rep(i, 1, n) {
		if (!innode[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		res.push_back(u);
		for (int v : g[u]) {
			if (!--innode[v]) {
				q.push(v);
			}
		}
	}
}

main() {
  //  int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, m) {
    char u, v;
    cin >> u >> v;
    g[u - 'A' + 1].push_back(v - 'A' + 1);
    innode[v - 'A' + 1]++;
  }
  AovSort(n);
  for (int v : res) cout << (char)(v + 'A' - 1) << ' ';
  return 0;
}