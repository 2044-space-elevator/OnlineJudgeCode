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

const int N = 1E5 + 5;
int dfn[N], dep[N], cnt = 0, from[N], to[N], dfn_number[N];
vct<int> E[N];

void dfs(int u, int fa) {
    dfn[u] = from[u] = to[u] = ++cnt;
    dep[u] = dep[fa] + 1;
    for (int v : E[u]) {
        if (v == fa) {
            continue;
        }
        dfs(v, u); 
        from[u] = min(from[u], from[v]);
        to[u] = max(to[u], to[v]);
    }
}

#define lc (2*p)
#define rc (2*p+1)
struct SegmentTree{
    int l, r, val, lazy;
}tree[N * 4];

void pushUp(int p) {
    tree[p].val = min(tree[lc].val, tree[rc].val);
}

void pushDown(int p) {
    if (tree[p].lazy) {
        tree[lc].lazy = max(tree[lc].lazy, tree[p].lazy);
        tree[rc].lazy = max(tree[rc].lazy, tree[p].lazy);
        tree[p].lazy = 0;
    }
}

void build(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
        tree[p].val = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushUp(p);
}

void update(int p, int l, int r, int val) {
    if (l <= tree[p].l && tree[p].r <= r) {
        tree[p].lazy = max(tree[p].lazy, val);
        return;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    pushDown(p);
    if (l <= mid) update(lc, l, r, val);
    if (r > mid) update(rc, l, r, val);
    pushUp(p);
}

int query(int p, int x) {
    if (x == tree[p].l && tree[p].r == x) {
        tree[p].val = max(tree[p].val, tree[p].lazy);
        tree[p].lazy = 0; 
        return tree[p].val;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    pushDown(p);
    int ans = 0;
    if (x <= mid) ans = query(lc, x);
    if (x > mid) ans = query(rc, x);
    pushUp(p);
    return ans;
}


main() {
    int n, m;
    cin >> n >> m;
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1, 0);
    rep(i, 1, n) {
        dfn_number[dfn[i]] = i;
    }
    build(1, 1, n);
    while (m--) {
        char c;
        cin >> c;
        int x;
        cin >> x;
        if (c == 'Q') {
            cout << dfn_number[query(1, dfn[x])] << endl;
        } else {
            update(1, from[x], to[x], dfn[x]);
        }
    }
//	int t; cin >> t; while (t--) solve();
	return 0;
}
