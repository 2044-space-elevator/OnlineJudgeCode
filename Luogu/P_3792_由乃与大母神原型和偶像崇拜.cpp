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

const int N = 5E5 + 5;
struct SegmentTree {
    int l, r;
    unsigned long long minv = ULLONG_MAX, maxv = 0, square = 0, sum = 0;
}tree[N * 4];
ull arr[N];
#define lc (2*p)
#define rc (2*(p)+1)

void pushUp(int p) {
    tree[p].maxv = max(tree[lc].maxv, tree[rc].maxv);
    tree[p].minv = min(tree[lc].minv, tree[rc].minv);
    tree[p].square = tree[lc].square + tree[rc].square;
    tree[p].sum = tree[lc].sum + tree[rc].sum;
}

void build(int p ,int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
        tree[p].maxv = tree[p].minv = tree[p].sum = arr[l];
        tree[p].square = arr[l] * arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushUp(p);
}

void update(int p, int l, ull val) {
    if (tree[p].l == l && tree[p].r == l) {
        tree[p].maxv = tree[p].minv = tree[p].sum = val;
        tree[p].square = val * val;
        return;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if (l <= mid) update(lc, l, val);
    if (l > mid) update(rc, l, val);
    pushUp(p);
}

SegmentTree query(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p];
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    SegmentTree ans;
    ans.maxv = 0, ans.minv = ULLONG_MAX, ans.sum = 0, ans.square = 0;
    if (l <= mid) {
        ans = query(lc, l, r);
    }
    if (r > mid) {
        SegmentTree tmp = query(rc, l, r);
        ans.maxv = max(ans.maxv, tmp.maxv);
        ans.minv = min(ans.minv, tmp.minv);
        ans.sum += tmp.sum;
        ans.square += tmp.square;
    }
    pushUp(p);
    return ans;
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> arr[i];
    }
    build(1, 1, n);
    while (m--) {
        int typ, l;
        cin >> typ >> l;
        if (typ == 1) {
            ull r;
            cin >> r;
            update(1, l, r);
        } else {
            int r;
            cin >> r;
            SegmentTree tmp = query(1, l, r);
            ull mi = tmp.minv, ma = tmp.maxv, su = tmp.sum, sq = tmp.square;
            if (ma - mi + 1 != r - l + 1) {
                cout << "yuanxing\n";
                continue;
            }
            ull summa = ma * (ma + 1ull) / 2ull;
            ull summi = mi * (mi - 1ull) / 2ull;
            if (summa - summi != su) {
                cout << "yuanxing\n";
                continue;
            }
            ull squma = ma * (ma + 1ull) * (2ull * ma + 1ull);
            ull squmi = (mi - 1ull) * (mi) * (2ull * mi - 1ull); 
            if (squma - squmi != sq * 6ull) {
                cout << "yuanxing\n";
                continue;
            }
            cout << "damushen\n";
        }
    }
//	int t; cin >> t; while (t--) solve();
	return 0;
}
