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

const int N = 27, M = 605;
vct<int> E[N];
int n, m, in[N];
vct<int> path;
int canconfirm = 0;
bool vis[N];
bool tpsearch() {
    canconfirm = 0;
    path.clear();
    memset(in, 0, sizeof in);
    rep(i, 1, n) {
        for (int v : E[i]) {
            in[v]++;
        }
    }
    memset(vis, 0, sizeof vis);
    queue<int> q;
    rep(i, 1, n) {
        if (!in[i] && E[i].size()) {
            q.push(i);
            canconfirm++;
        }
    }
    if (canconfirm != 1) canconfirm = 0;
    while (q.size()) {
        int tmp = 0;
        int u = q.front(); q.pop();
        vis[u] = 1;
        path.push_back(u);
        for (int v : E[u]) {
            if (vis[v]) return 0;
            if (!--in[v]) { q.push(v); tmp++;}
            tmp = tmp == 1 ? 1 : 0;
            canconfirm &= tmp;           
        }
    }
    rep (i, 1, n) if (in[i]) return 0;
    return 1;
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, m) {
        char a, op, b;
        cin >> a >> op >> b;
        //cout << a << ' ' << op << ' ' << b << ' ' << i << endl;
            //if (i == 6) cout << "That's why I beifen";
        if (a == b) {
            printf("Inconsistency found after %d relations.", i);
            return 0;
        }
        E[a - 'A' + 1].push_back(b - 'A' + 1);
        bool res = tpsearch();
        if (!res) {
            printf("Inconsistency found after %d relations.", i);
            return 0;
        }
        if (res && !canconfirm && i == m) {
            rep(i, 1, n) {
                if (!vis[i]) goto _;
            }
            cout << "Sorted sequence cannot be determined.";
            return 0;
        }
        if (res && canconfirm) {
            rep(i, 1, n) {
                if (!vis[i]) goto _;
            }
            printf("Sorted sequence determined after %d relations: ", i);
            for (int v : path) {
                cout << (char)(v + 'A' - 1);
            }
            cout << ".";
            return 0;
        }
        _:;
    }
           // cout << "Sorted sequence cannot be determined.";
	return 0;
}
