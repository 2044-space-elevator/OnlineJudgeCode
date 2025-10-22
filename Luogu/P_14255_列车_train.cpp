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

const int N = 1e5 + 5;
struct SegmentTree {
    int l, r, frl = N, tor = 0, lazyl = N, lazyr = 0;
}tree[4 * N];

#define lc (2*p)
#define rc (2*p+1)

void pushDown(int p) {
    if (tree[p].lazyl != N) {
        tree[lc].lazyl = min(tree[p].lazyl, tree[lc].lazyl);
        tree[lc].frl = min(tree[lc].frl, tree[p].lazyl);
        tree[rc].lazyl = min(tree[p].lazyl, tree[rc].lazyl);
        tree[rc].frl = min(tree[rc].frl, tree[p].lazyl);
        tree[p].lazyl = N;
    }
    if (tree[p].lazyr) {
        tree[lc].lazyr = max(tree[p].lazyr, tree[lc].lazyr);
        tree[lc].tor = max(tree[lc].tor, tree[p].lazyr);
        tree[rc].lazyr = max(tree[p].lazyr, tree[rc].lazyr);
        tree[rc].tor = max(tree[rc].tor, tree[p].lazyr);
        tree[p].lazyr = 0;
    }
}

void build(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    tree[p].frl = tree[p].lazyl = N;
    tree[p].tor = tree[p].lazyr = 0;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}

void update(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        tree[p].frl = min(tree[p].frl, l);
        tree[p].tor = max(tree[p].tor, r);
        tree[p].lazyl = min(tree[p].lazyl, l);
        tree[p].lazyr = max(tree[p].lazyr, r);
        return;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    pushDown(p);
    if (l <= mid) update(lc, l, r);
    if (r > mid) update(rc, l, r);
}

pair<int, int> query(int p, int x) {
    if (x == tree[p].l && tree[p].r == x) {
        return {tree[p].frl, tree[p].tor};
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    pushDown(p);
    if (x <= mid) return query(lc, x);
    if (x > mid) return query(rc, x);
}

ll p[N];

void solve() {
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> p[i];
    }
    build(1, 1, n);
    rep(tt, 1, m) {
        int op, l, r;
        cin >> op >> l >> r;
        // if (n == 4 && m == 6) continue;
        if (op == 1) {
            update(1, l, r);
            continue;
        } 
        // if (l > r) {
        //     cout << "-1\n";
        //     continue;
        // }
        int nxt = r;
        ll ans = p[n];
        rep(i, r, n) {
            pair<int ,int > tmp = query(1, i);
            if (tmp.first > l) {
                ans = min(ans, p[i] - p[l]);
                // break;
            } else {
                ans = min(ans, p[i] - p[tmp.first - 1]);
            }
        }
        // while (p[nxt] - p[l] < ans) {
        // // cout << query(1, 5).first << ' ' << query(1, 5).second << endl;
        //     pair<int, int> tmp = query(1, nxt);
        //     // cout << tmp.first << ' ' << tmp.second << ' ' << nxt << ' ' << endl;
        //     if (tmp.first > l) {
        //         ans = min(ans, p[nxt] - p[l]);
        //         break;
        //     } else {
        //         ans = min(ans, p[nxt] - p[tmp.first - 1]);
        //     }
        //     if (tmp.second)
        //         nxt = tmp.second + 1;
        //     if (nxt > n) {
        //         break;
        //     }
        // }
        if (ans == p[n]) {
            cout << "-1\n";
            continue;
        }
        cout << ans << '\n';
    }
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t; cin >> t; while (t--) solve();
	return 0;
}
