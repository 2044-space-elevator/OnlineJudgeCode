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

const int N = 5E5 + 5;
#define lc (p*2)
#define rc (p*2+1) 
struct T {
    int lx, rx, ans, mx, mn, l, r;
    // lx Ai - Bj i < j
    // rx -Bj + Ak j < k
    // mx max{A}
    // mn min{B}
}tree[(N * 4)];

int arr[N], brr[N];

void pushUp(int p) {
    tree[p].mx = max(tree[lc].mx, tree[rc].mx);
    tree[p].mn = min(tree[lc].mn, tree[rc].mn);
    tree[p].lx = max({
        tree[lc].lx,
        tree[rc].lx,
        tree[lc].mx - tree[rc].mn
    });
    tree[p].rx = max({
        tree[lc].rx,
        tree[rc].rx,
        tree[rc].mx - tree[lc].mn
    });
    tree[p].ans = max({
        tree[lc].ans,
        tree[rc].ans,
        tree[lc].lx + tree[rc].mx,
        tree[lc].mx + tree[rc].rx
    });
}

void build(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
        tree[p].mx = arr[l], tree[p].mn = brr[l];
        tree[p].ans = tree[p].lx = tree[p].rx = -1e9;
        return;
    }
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushUp(p);
}

void updateA(int p, int pos, int val) {
    if (tree[p].l == tree[p].r) {
        tree[p].mx = val;
        return;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if (pos <= mid) updateA(lc, pos, val);
    else updateA(rc, pos, val);
    pushUp(p);
}

void updateB(int p, int pos, int val) {
    if (tree[p].l == tree[p].r) {
        tree[p].mn = val;
        return;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if (pos <= mid) updateB(lc, pos, val);
    else updateB(rc, pos, val);
    pushUp(p);
}

T query(int p, int l, int r) {
    // cout << p << ' ' << l << ' ' << r << ' ' << tree[p].l << ' ' << tree[p].r << endl;
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p];
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if (r <= mid) return query(lc, l, r);
    if (l > mid) return query(rc, l, r);
    T fs = query(lc, l, r);
    T sc = query(rc, l, r);
    T res;
    res.mx = max(fs.mx, sc.mx);
    res.mn = min(fs.mn, sc.mn);
    res.lx = max({
        fs.lx,
        sc.lx,
        fs.mx - sc.mn
    });
    res.rx = max({
        fs.rx,
        sc.rx,
        sc.mx - fs.mn
    });
    res.ans = max({
        fs.ans,
        sc.ans,
        fs.lx + sc.mx,
        fs.mx + sc.rx
    });
    return res;
}


main() {
//	int t; cin >> t; while (t--) solve();
    int n, q;
    cin >> n >> q;
    rep(i, 1, n) {
        cin >> arr[i];
    }
    rep(i, 1, n) {
        cin >> brr[i];
    }
    build(1, 1, n);
    // cout << tree[1].ans;
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) updateA(1, l, r);
        if (op == 2) updateB(1, l, r);
        if (op == 3) {
            cout << query(1, l, r).ans << endl;
        }
    }
	return 0;
}
