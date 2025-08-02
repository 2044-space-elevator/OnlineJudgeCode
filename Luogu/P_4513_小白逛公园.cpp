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

#define lc(x) ((x)*2)
#define rc(x) (((x)*2)+1)

const int N = 5E5 + 5;
struct T {
    int l, r, val, maxium, ls, rs;
}tree[N * 4];
int arr[N], n;

void pushUp(int ind) {
    tree[ind].val = tree[lc(ind)].val + tree[rc(ind)].val;
    tree[ind].ls = max(tree[lc(ind)].ls, tree[lc(ind)].val + tree[rc(ind)].ls);
    tree[ind].rs = max(tree[rc(ind)].rs, tree[rc(ind)].val + tree[lc(ind)].rs);
    tree[ind].maxium = max({
        tree[rc(ind)].maxium,
        tree[lc(ind)].maxium,
        tree[lc(ind)].rs + tree[rc(ind)].ls
    });
}

void build(int x, int l, int r) {
    tree[x].l = l, tree[x].r = r;
    if (l == r) {
        tree[x].val = tree[x].maxium = tree[x].ls = tree[x].rs = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
    pushUp(x);
}

void update(int x, int pos, int val) {
    if (tree[x].l == tree[x].r) {
        tree[x].val = tree[x].maxium = tree[x].ls = tree[x].rs = val;
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2; 
    if (pos <= mid) update(lc(x), pos, val);
    else  update(rc(x), pos, val);
    pushUp(x);
}


T query(int x, int l, int r) {
    if (l <= tree[x].l && tree[x].r <= r) {
        return tree[x];
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (r <= mid) return query(lc(x), l, r);
    if (mid < l) return query(rc(x), l, r);
    T fs = query(lc(x), l, r);
    T sc = query(rc(x), l, r);
    T res;
    res.ls = max(fs.ls, fs.val + sc.ls);
    res.rs = max(sc.rs, fs.rs + sc.val);
    res.val = fs.val + sc.val;
    res.maxium = max({fs.maxium, sc.maxium, fs.rs + sc.ls}); 
    return res;
}


main() {
//	int t; cin >> t; while (t--) solve();
    int q;
    cin >> n >> q;
    rep(i, 1, n) cin >> arr[i];
    build(1, 1, n);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            if (r < l) swap(l, r);
            T tmp = query(1, l, r);
            cout << tmp.maxium << endl;
        }
        if (op == 2) update(1, l, r);
    }
    // cout << 114514;
	return 0;
}
