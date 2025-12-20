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

const int N = 3E5 + 5;

struct trie {
	int cnt;
	map<int, int> nex[N];
	int ind[N];
	vector<int> end[N];
	void insert(int num, int fr, int to) {
		int cur = ind[fr];
		if (!nex[cur][num]) {
			nex[cur][num] = ++cnt;
		}
		cur = nex[cur][num];
		end[cur].push_back(to);
		ind[to] = cur;
	}
}tree;

vector<int> ans;

void dfs(int p) {
	for (int v : tree.end[p]) {
		ans.push_back(v);
	}
	for (map<int, int>::iterator it = tree.nex[p].begin(); it != tree.nex[p].end(); ++it) {
		dfs(it->second);
	}
}


main() {
//	int t; cin >> t; while (t--) solve();
	int n;
	cin >> n;
	rep(i, 1, n) {
		int xi, yi;
		cin >> xi >> yi;
		tree.insert(yi, xi, i);
	}
	dfs(0);
	for (int  v : ans) cout << v << ' ';
	return 0;
}
