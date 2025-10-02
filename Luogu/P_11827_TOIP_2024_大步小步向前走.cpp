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
int jumps[N];
map<int, bool> pole;
int n, k, e;
vector<int> paths;

void dfs(int now) {
    if (now == e) {
        cout << paths.size() << endl;
        for (auto v : paths) {
            cout << v << ' ';
        } 
        exit(0);
    }
    rep(i, 1, k) {
        if (now + jumps[i] > e || pole[now + jumps[i]]) {
            continue;
        }
        paths.push_back(now + jumps[i]);
        dfs(now + jumps[i]);
        paths.pop_back();
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> k >> e;
    rep(i, 1, n) {
        int x; cin >> x;
        pole[x] = 1;
    }
    rep(i, 1, k) {
        cin >> jumps[i];
    }
    sort(jumps + 1, jumps + k + 1, greater<int>());
    dfs(0);
    cout << -1;
	return 0;
}
