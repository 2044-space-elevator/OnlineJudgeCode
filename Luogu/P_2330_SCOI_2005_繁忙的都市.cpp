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

struct Edge {
    int u, v, c;
}E[8005];

bool cmp(Edge a, Edge b) { return a.c < b.c; }
int n, m;
int fa[8005];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, m) {
        cin >> E[i].u >> E[i].v >> E[i].c;
        fa[i] = i;
    }
    int cnt = n - 1;
    cout << cnt << ' ';
    sort(E + 1, E + m + 1, cmp);
    rep(i, 1, m) {
        if (!cnt) {
            break;
        }
        int nod1 = find(E[i].u), nod2 = find(E[i].v);
        if (nod1 == nod2) {
            continue;
        }
        fa[nod1] = nod2;
        cnt--;
        if (cnt == 0) {
            cout << E[i].c;
        }
    }
	return 0;
}
