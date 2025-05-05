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
ll n, mod, a1, a2, p, q;
struct Matrix {
    ll mat[3][3];
    Matrix() {
        memset(mat, 0, sizeof mat);
    }
    Matrix operator * (const Matrix b) {
        Matrix ans;
        rep(i, 1, 2) {
            rep(j, 1, 2) {
                rep(k, 1, 2) {
                    ans.mat[i][j] += mat[i][k] * b.mat[k][j];
                    ans.mat[i][j] %= mod;
                }
            }
        }
        return ans;
    }
}fst, dw;

Matrix qpow(Matrix a, ll b) {
    Matrix res;
    rep(i, 1, 2) res.mat[i][i] = 1;
    while (b) {
        if (b & 1) res =  res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

main() {
    cin >> p >> q >> a1 >> a2 >> n >> mod;
    if (n == 1) cout << a1 % mod;
    else if (n == 2) cout << a2 % mod;
    fst.mat[1][1] = a2, fst.mat[1][2] = a1;
    dw.mat[1][1] = p;
    dw.mat[1][2] = 1;
    dw.mat[2][1] = q;
    dw = fst * qpow(dw, n - 2);
    cout << dw.mat[1][1]; 
//	int t; cin >> t; while (t--) solve();
	return 0;
}
