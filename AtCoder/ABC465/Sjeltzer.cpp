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
const int N = 3E5 + 5;

int n;

struct drink {
	int w0, w1, w2, w3, w4, w5;
	ll V;
}drinks[N];

bool cmp(drink a, drink b) {
	if (a.w0 != b.w0) return a.w0 < b.w0;
	if (a.w1 != b.w1) return a.w1 < b.w1;
	if (a.w2 != b.w2) return a.w2 < b.w2;
	if (a.w3 != b.w3) return a.w3 < b.w3;
	if (a.w4 != b.w4) return a.w4 < b.w4;
	if (a.w5 != b.w5) return a.w5 < b.w5;
	return a.V < b.V;
}

int w[6][N];
ll pre[N];

main() {
	cin >> n;
	rep(i, 1, n) {
		string a; 
		cin >> a >> drinks[i].V;
		drinks[i].w0 = a[0] - '0';
		drinks[i].w1 = a[1] - '0';
		drinks[i].w2 = a[2] - '0';
		drinks[i].w3 = a[3] - '0';
		drinks[i].w4 = a[4] - '0';
		drinks[i].w5 = a[5] - '0';
	}
	sort(drinks + 1, drinks + n + 1, cmp);
	rep(i, 1, n) {
		w[0][i] = drinks[i].w0;
		w[1][i] = drinks[i].w1;
		w[2][i] = drinks[i].w2;
		w[3][i] = drinks[i].w3;
		w[4][i] = drinks[i].w4;
		w[5][i] = drinks[i].w5;
		pre[i] = pre[i - 1] + drinks[i].V;
	}
	
	int q;
	cin >> q;
	while (q--) {
		string x, y; cin >> x >> y;
		int l = lower_bound(w[0] + 1, w[0] + n + 1, x[0] - '0') - w[0];
		int r = upper_bound(w[0] + 1, w[0] + n + 1, y[0] - '0') - w[0] - 1;

		if (l > r) { cout << "0\n"; continue; }
		l = lower_bound(w[1] + l , w[1] + r + 1, x[1] - '0') - w[1];
		r = upper_bound(w[1] + l , w[1] + r + 1, y[1] - '0') - w[1] - 1;

		if (l > r) { cout << "0\n"; continue; }
		l = lower_bound(w[2] + l, w[2] + r + 1, x[2] - '0') - w[2];
		r = upper_bound(w[2] + l, w[2] + r + 1, y[2] - '0') - w[2] - 1;

		if (l > r) { cout << "0\n"; continue; }
		l = lower_bound(w[3] + l, w[3] + r + 1, x[3] - '0') - w[3];
		r = upper_bound(w[3] + l, w[3] + r + 1, y[3] - '0') - w[3] - 1;

		if (l > r) { cout << "0\n"; continue; }
		l = lower_bound(w[4] + l, w[4] + r + 1, x[4] - '0') - w[4];
		r = upper_bound(w[4] + l, w[4] + r + 1, y[4] - '0') - w[4] - 1;

		if (l > r) { cout << "0\n"; continue; }
		l = lower_bound(w[5] + l, w[5] + r + 1, x[5] - '0') - w[5];
		r = upper_bound(w[5] + l, w[5] + r + 1, y[5] - '0') - w[5] - 1;
		if (l > r) { cout << "0\n"; continue; }
		// cout << r << ' ' << l << ' ';
		ll ans = pre[r] - pre[l - 1];
		cout << ans << '\n';
	}

//	int t; cin >> t; while (t--) solve();
	return 0;
}
