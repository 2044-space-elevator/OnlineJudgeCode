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

const ll mod = 1e9 + 7;
ll n; stg s;
struct Matrix {
	ll mat[27][27];
	Matrix() {
		memset(mat, 0, sizeof mat);
	}
	Matrix operator * (Matrix const &b) {
		Matrix ans;
		rep(i, 1, 26)
			rep(j, 1, 26)
				rep(k, 1, 26)
					ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * b.mat[k][j] % mod) % mod;
		return ans;
	}
};

Matrix qpow(Matrix a, ll b) {
	Matrix ans;
	rep(i, 1, 26) ans.mat[i][i] = 1;
	while (b) {
		if (b & 1ll) ans = ans * a;
		b >>= 1ll;
		a = a * a;
	}
	return ans;
}

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> s;
	Matrix init;
	rep(i, 1, 26) rep(j, 1, 26) init.mat[i][j] = 1;
	repq(i, 1, s.size()) {
		init.mat[s[i - 1] - 'a' + 1][s[i] - 'a' + 1] = 0;
	}
	Matrix dp;
	ll ans = 0;
	init = qpow(init, n - 1ll);
	rep(i, 1, 26) rep(j, 1, 26) ans = (ans + init.mat[i][j]) % mod;
	cout << ans;
	return 0;
}
