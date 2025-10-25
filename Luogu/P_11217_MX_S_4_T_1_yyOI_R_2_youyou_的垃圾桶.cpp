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

#define ull ll
const int N = 2E5 + 5;

#define lc (2*p)
#define rc (2*p+1)

struct SegmentTree {
	int l, r;
	ull val, lazy;
}tree[N * 4];

ull arr[N];

void pushUp(int p) {
	tree[p].val = tree[lc].val + tree[rc].val;
}

void pushDown(int p) {
	if (tree[p].lazy) {
		int mid = (tree[p].l + tree[p].r) / 2;
		tree[lc].val += (mid - tree[p].l + 1ll) * tree[p].lazy;
		tree[rc].val += (tree[p].r - mid) * tree[p].lazy;
		tree[lc].lazy += tree[p].lazy;
		tree[rc].lazy += tree[p].lazy;
		tree[p].lazy = 0;
	}
}

void build(int p, int l, int r) {
	tree[p].l = l, tree[p].r = r;
	if (l == r) {
		tree[p].val = arr[l];
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
		tree[p].val += (tree[p].r - tree[p].l + 1ll) * val;
		tree[p].lazy += val;
		return;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	pushDown(p);
	if (l <= mid) update(lc, l, r, val);
	if (r > mid) update(rc, l, r, val);
	pushUp(p);
}

ull query(int p, int l, int r) {
	if (l <= tree[p].l && tree[p].r <= r) {
		return tree[p].val;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	ull ans = 0;
	pushDown(p);
	if (l <= mid) ans += query(lc, l, r);
	if (r > mid) ans += query(rc, l, r);
	pushUp(p);
	return ans;
}

ull qpow(ull a, ull b) {
	ull ans = 1;
	while (b) {
		if (b & 1) {
			ans *= a;
		}
		a *= a;
		b >>= 1;
	}
	return ans;
}

int ask(int p, ll res, int now) {
	if (tree[p].l == tree[p].r) {
		return tree[p].l;
	}
	pushDown(p);
	if (tree[lc].val * (1ll << (now - 1ll)) >= res) {
		return ask(lc, res, now);
	}
	return ask(rc, res - tree[lc].val * (1ll << (now - 1ll)), now);
}

char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define int ull
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}

void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}

#undef int


main() {
//	int t; cin >> t; while (t--) solve();ull ans = 0;
	int n, m;
	ull W;
	n = read(), m = read(), W = read();
	rep(i, 1, n) {
		arr[i] = read();
	}
	build(1, 1, n);
	while (m--) {
		int l, r;
		ull d;
		l = read(), r = read(), d = read();
		update(1, l, r, d);
		ull sum = tree[1].val;
		ll spare = W;
		int now = 0;

		// while (left <= right) {
		// 	int mid = (left + right) / 2;
		// 	if ((qpow(2, mid + 1) - 1ull) * sum >= spare) {
		// 		right = mid - 1;
		// 	} else left = mid + 1;
		// }

		// ans += right * n;
		// now = right + 1;
		ll kk = 2;
		for (now = 1; ; now++) {
			if (sum * (kk - 1ll) >= W) {
				break;
			}
			kk *= 2ll;
		}
		// cout << now << ' ' << ans << ' ' << sum << '\n';
		// left = 1;
		// right = n;
		// while (left <= right) {
		// 	int mid = (left + right) / 2;
		// 	if (query(1, 1, mid) * qpow(2, now) >= spare) {
		// 		right = mid - 1;
		// 	} else left = mid + 1;
		// }
		// rep(i, 1, n) {
		// 	spare -= qpow(2, now) * query(1, i, i);
		// 	ans++;
		// 	if (spare <= 0) break;
		// }
		// cout << now << endl;
		write((now - 1ll) * n + ask(1, W - sum * (kk / 2ll - 1ll), now) - 1);
	putchar('\n');
	}
	return 0;
}
