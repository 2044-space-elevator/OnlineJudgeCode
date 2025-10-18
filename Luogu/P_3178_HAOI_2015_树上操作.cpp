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

#define int ll
const int N = 1E5 + 5;
struct SegmentTree {
    int l, r;
    ll val, lazy;
}tree[N * 4];

int arr[N], dfn[N], dfn_number[N], lst_chosen[N], n, m, from[N], to[N], fat[N];
vct<int> E[N];

#define lc (2*p)
#define rc (2*p+1)

void pushUp(int p) {
    tree[p].val = tree[lc].val + tree[rc].val;
}

void pushDown(int p) {
    if (tree[p].lazy) {
        int mid = (tree[p].l + tree[p].r) / 2;
        tree[lc].val += tree[p].lazy * (mid - tree[p].l + 1);
        tree[rc].val += tree[p].lazy * (tree[p].r - mid);
        tree[lc].lazy += tree[p].lazy;
        tree[rc].lazy += tree[p].lazy;
        tree[p].lazy = 0;
    }
}

void build(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
        tree[p].val = arr[dfn_number[l]];
        tree[p].lazy = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushUp(p);
}

void update(int p, int l, int r, int val) {
    if (l <= tree[p].l && tree[p].r <= r) {
        tree[p].lazy += val;
        tree[p].val += (tree[p].r - tree[p].l + 1) * val;
        return;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    pushDown(p);
    if (l <= mid) update(lc, l, r, val);
    if (r > mid) update(rc, l, r, val);
    pushUp(p);
}

ll query(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].val;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    pushDown(p);
    ll ans =0;
    if (l <= mid) ans += query(lc, l, r);
    if (r > mid) ans += query(rc, l, r);
    pushUp(p);
    return ans;
}
int cnt = 0;

void dfs(int u, int fa) {
    fat[u] = fa;
    from[u] = to[u] = dfn[u] = ++cnt;
    dfn_number[cnt] = u;
    if (dfn[u] == dfn[fa] + 1) {
        lst_chosen[u] = lst_chosen[fa];
    } 
    else lst_chosen[u] = u;
    if(u == 1) lst_chosen[1] = 1;
    for (int v : E[u]) {
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        from[u] = min(from[v], from[u]);
        to[u] = max(to[v], to[u]);
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> arr[i];
    }
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0);
    build(1, 1, n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            ll a;
            cin >> x >> a;
            update(1, dfn[x], dfn[x], a);
        } 
        if (op == 2) {
            int x;
            ll a;
            cin >> x >> a;
            update(1, from[x], to[x], a);
        }
        if (op == 3) {
            int x;
            cin >> x;
            ll ans = 0;
            while (x) {
                int tmp = lst_chosen[x];
                ans += query(1, dfn[tmp], dfn[x]);
                x = fat[tmp];
            }
            cout << ans << endl;
        }
    }
	return 0;
}
