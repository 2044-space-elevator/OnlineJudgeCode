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
const int N = 1e6 + 5;

struct tree {
    int l, r;
    ll data, lazy;
}tree[N * 4];

ll arr[N];
void pushUp(int i) {
    tree[i].data = min(tree[i * 2].data, tree[i * 2 + 1].data);
}

void pushDown(int i) {
    if (tree[i].lazy) {
        int mid = (tree[i].l + tree[i].r) >> 1;
        tree[i * 2].data += tree[i].lazy;
        tree[i * 2].lazy += tree[i].lazy;
        tree[i * 2 + 1].data += tree[i].lazy;
        tree[i * 2 + 1].lazy += tree[i].lazy;
        tree[i].lazy = 0;
    }
}

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (l == r) {
        tree[p].data =arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    pushUp(p);
}

void update(int p, int l, int r, ll k) {
    if (l <= tree[p].l && r >= tree[p].r) {
        tree[p].data += k;
        tree[p].lazy += k;
        return;
    }
    pushDown(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid) update(p * 2, l, r, k);
    if (r > mid) update(p * 2  + 1, l, r, k);
    pushUp(p);
}

ll query(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].data;
    }
    pushDown(p);
    ll ans = 1e18;
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid) ans = min(ans, query(p * 2, l, r));
    if (r > mid) ans = min(ans, query(p * 2 + 1, l, r));
    return ans;
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n, k;
    cin >> n >> k;
    rep(i, 1, n) {
        cin >> arr[i];
    }
    build(1, 1, n);
    ll ans = 0;
    rep(l, 1, n - k + 1) {
        int r = l + k - 1;
        ll tmp = query(1, l, r);
        ans += tmp;
        update(1, l, r, -tmp);
    }
    rep(i, 1, n) {
        ans += query(1, i, i);
    }
    cout << ans;
	return 0;
}
